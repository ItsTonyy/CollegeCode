#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <linux/limits.h>

char** inputTokens = NULL;
int inputTokensCount = 0, isBatchMode = 0;
char** searchPaths = NULL;
int searchPathsCount = 0;
char** commandList = NULL;
int commandListCount = 0;

void printError() {
  char errorMessage[30] = "An error has occurred\n";
  write(STDERR_FILENO, errorMessage, strlen(errorMessage));
}

int compareStrings(char* str1, char* str2) {
  return (strcmp(str1, str2) == 0);
}

int findStringInArray(char *str, char *arr[], int size) {
  for (int i = 0; i < size; i++) {
    if (strcmp(str, arr[i]) == 0) {
      return i;
    }
  }
  return -1;
}

void separateInput(char* rawInput) {
  char* stringCopy = strdup(rawInput);
  char* currentToken;

  while ((currentToken = strsep(&stringCopy, " ")) != NULL) {
    if (currentToken[0] == '\0' || strspn(currentToken, " ") == strlen(currentToken)) {
      continue;
    }

    inputTokens = realloc(inputTokens, sizeof(char*) * (inputTokensCount + 1));
    if (inputTokens == NULL) {
      perror("Memory allocation failed");
      exit(1);
    }

    inputTokens[inputTokensCount] = strdup(currentToken);
    inputTokensCount++;
  }
  inputTokens = realloc(inputTokens, sizeof(char*) * (inputTokensCount + 1));
  inputTokens[inputTokensCount] = NULL;
  free(stringCopy);
}

void separateCommands(char* rawInput) {
  char* stringCopy = strdup(rawInput);
  char* currentCommand;

  while ((currentCommand = strsep(&stringCopy, "&")) != NULL) {
    if (*currentCommand == '\0') continue;

    commandList = realloc(commandList, sizeof(char*) * (commandListCount + 1));
    if (commandList == NULL) {
      perror("Memory allocation failed");
      exit(1);
    }

    commandList[commandListCount] = strdup(currentCommand);
    commandListCount++;
  }
  free(stringCopy);
}

void separateStringsByChar(char*** stringArray, int* stringCount, char separator) {
  char* currentString = NULL, *currentStringPart;
  
  int newStringCount = 0, partLength, len;
  char** tempArray = NULL;
  
  for (int i = 0; i < *stringCount; i++) {
    currentString = strdup((*stringArray)[i]);
    len = strlen(currentString);
    
    int lastSeparatorPos = -1;
    for (int j = 0; j <= len; j++) {
      if (currentString[j] == separator || j == len) {
        if (j - lastSeparatorPos > 1) {
          partLength = j - lastSeparatorPos - 1;
          currentStringPart = (char*)malloc((partLength + 1) * sizeof(char));
          
          for (int k = lastSeparatorPos + 1; k < j; k++) {
            currentStringPart[k - lastSeparatorPos - 1] = currentString[k];
          }
          currentStringPart[partLength] = '\0';
          
          tempArray = realloc(tempArray, sizeof(char*) * (newStringCount + 1));
          if (tempArray == NULL) {
            perror("Memory allocation failed");
            exit(1);
          }
      
          tempArray[newStringCount] = currentStringPart;
          newStringCount++;
        }
        
        if (currentString[j] == separator) {
          tempArray = realloc(tempArray, sizeof(char*) * (newStringCount + 1));
          if (tempArray == NULL) {
            perror("Memory allocation failed");
            exit(1);
          }
      
          char separatorString[2];
          separatorString[0] = separator;
          separatorString[1] = '\0';
          tempArray[newStringCount] = strdup(separatorString);
          newStringCount++;
          lastSeparatorPos = j;
        }
      }
    }
    
    free(currentString);
  }
  
  *stringArray = realloc(*stringArray, sizeof(char*) * newStringCount);
  for (int i = 0; i < newStringCount; i++) {
    (*stringArray)[i] = (char*)malloc((strlen(tempArray[i]) + 1) * sizeof(char));
    strcpy((*stringArray)[i], tempArray[i]);
  }

  *stringCount = newStringCount;

  for (int i = 0; i < newStringCount; i++) {
    free(tempArray[i]);
  }
  free(tempArray);
}

void cleanupLoop() {
  for (int i = 0; i < inputTokensCount; i++) {
    free(inputTokens[i]);
  }
  free(inputTokens);
  inputTokens = NULL;
  inputTokensCount = 0;
}

void initializePaths() {
  searchPathsCount++;
  searchPaths = malloc(searchPathsCount * sizeof(char*));
  if (searchPaths == NULL) {
    printf("Malloc error\n");
    exit(1);
  }

  searchPaths[0] = strdup("/bin");
}

int cdCommand() {
  if (inputTokensCount != 2) {
    printError();
    return 1;
  }

  chdir(inputTokens[1]);
  return 0;
}

int pathCommand() {
  if (inputTokensCount == 1) {
    searchPaths = NULL;
    searchPathsCount = 0;
    return 0;
  }

  for (int i = 1; i < inputTokensCount; i++) {
    searchPaths = realloc(searchPaths, sizeof(char*) * (searchPathsCount + 1));
    if (searchPaths == NULL) {
      perror("Memory allocation failed");
      return 1;
    }

    searchPaths[searchPathsCount] = strdup(inputTokens[i]);
    searchPathsCount++;
  }
  return 0;
}

int main(int argc, char* argv[]) {
  char *input, *rawInput = NULL;
  size_t len = 0;
  FILE* file = NULL;
  int reopenStd = 0;
  int saved_stdout = dup(STDOUT_FILENO);
  int saved_stderr = dup(STDERR_FILENO);
  int shouldExit = 0;

  if (argc > 1) {
    if (argc == 2) {
      isBatchMode = 1;
      file = fopen(argv[1], "r");
      if (file == NULL) {
        printError();
        exit(1);
      }
    } else {
      printError();
      exit(1);
    }
  }

  initializePaths();

  while(1) {
    if (!isBatchMode) {
      printf("wish> ");
    }
    int getlineReturn = getline(&input, &len, file ? file : stdin);

    if (getlineReturn == -1) {
      cleanupLoop();
      break;
    }

    if (strcmp(input, "\n\0") == 0) {
      cleanupLoop();
      continue;
    }

    input[strcspn(input, "\n")] = 0;

    separateCommands(input);
    for (int i = 0; i < commandListCount; i++) {
      inputTokens = NULL;
      inputTokensCount = 0;

      rawInput = strdup(commandList[i]);
      separateInput(rawInput);

      if (!inputTokensCount) {
        cleanupLoop();
        continue;
      }

      if (compareStrings(inputTokens[0], "exit")) {
        if (inputTokensCount > 1) {
          printError();
          cleanupLoop();
          continue;
        }

        cleanupLoop();
        shouldExit = 1;
        break;
      }

      reopenStd = 0;
      if (strchr(rawInput, '>')) {
        int redirectionSymbolPosition = findStringInArray(">", inputTokens, inputTokensCount);

        if (redirectionSymbolPosition == -1) {
          separateStringsByChar(&inputTokens, &inputTokensCount, '>');
          redirectionSymbolPosition = findStringInArray(">", inputTokens, inputTokensCount);
        }

        if (redirectionSymbolPosition > -1) {
          if (redirectionSymbolPosition != inputTokensCount-2 || redirectionSymbolPosition == 0)  {
            printError();
            cleanupLoop();
            continue;
          }

          freopen(inputTokens[inputTokensCount-1], "w", stdout);
          freopen(inputTokens[inputTokensCount-1], "w", stderr);
          reopenStd = 1;
        }
      }

      if (compareStrings(inputTokens[0], "cd")) {
        cdCommand();
        cleanupLoop();
        continue;
      }

      if (compareStrings(inputTokens[0], "path")) {
        pathCommand();
        cleanupLoop();
        continue;
      }

      pid_t pid = fork();
      if (pid == 0) {
        char path[PATH_MAX+1];
        for (int j = 0; j < searchPathsCount; j++) {
          snprintf(path, sizeof(path), "%s/%s", searchPaths[j], inputTokens[0]);
          int execvReturn = 0;
          if (reopenStd) {
            char* newInputTokens[inputTokensCount-1];
            for (int k = 0; k < inputTokensCount-1; k++) {
              newInputTokens[k] = strdup(inputTokens[k]);
            }
            newInputTokens[inputTokensCount-2] = NULL;
            execvReturn = execv(path, newInputTokens);
            if (execvReturn == -1 && j != searchPathsCount-1) {
              continue;
            }
          } else {
            execvReturn = execv(path, inputTokens);
            if (execvReturn == -1 && j != searchPathsCount-1) {
              continue;
            }
          }
        }
        cleanupLoop();
        printError();
        exit(1);
      }
    }
  
    if (shouldExit) {
      cleanupLoop();
      for (int i = 0; i < commandListCount; i++) {
        free(commandList[i]);
      }
      free(commandList);
      commandList = NULL;
      commandListCount = 0;
      break;
    }

    for (int i = 0; i < commandListCount; i++) {
      wait(NULL);
    }

    if (reopenStd) {
      dup2(saved_stdout, STDOUT_FILENO);
      dup2(saved_stderr, STDERR_FILENO);
    }

    cleanupLoop();
    for (int i = 0; i < commandListCount; i++) {
      free(commandList[i]);
    }
    free(commandList);
    commandList = NULL;
    commandListCount = 0;
  }
  
  free(rawInput);
  exit(0);
}
