package OOP.LearningStuff;


public class exception {
  public static void main(String[] args) {
    String phrase = null;
    String newPhrase;
    try {
      newPhrase = phrase.toUpperCase();
      System.out.println(newPhrase);
    } catch (NullPointerException e) {
      System.out.println("empty phrase, associanting default phrase automatically.");
      phrase = "this is the default phrase";
      newPhrase = phrase.toUpperCase();
      System.out.println(newPhrase);
    }
  }
}

// out: THIS IS THE DEFAULT PHRASE