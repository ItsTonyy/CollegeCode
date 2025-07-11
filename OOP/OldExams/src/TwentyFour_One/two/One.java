package twentyFour.two;

import java.util.ArrayList;
import java.util.Scanner;

class Utilidades {
  public static ArrayList<String> getPalavroes() {
    ArrayList<String> palavroes = new ArrayList<String>();
    palavroes.add("porra");
    palavroes.add("caralho");
    palavroes.add("fodase");
    return palavroes;
  }
}

class Phrase {
  String phrase;
  public void addPhrase() {
    Scanner scanner = new Scanner(System.in);
    phrase = scanner.nextLine();
  }

  public String getPhrase() {
    return phrase;
  }

  public boolean Moderar(String phrase) {
    String[] palavrasNaFrase = phrase.split(" ");
    int contador = 0;

    for(String palavra1 : Utilidades.getPalavroes()) {
      for(String palavra2: palavrasNaFrase) {
        if(palavra2.equals(palavra1)) {
          contador++;
        }
      }
    }
    return contador > 0;
  }
}

public class One {
  public static void main(String[] args) {
    Utilidades utilidades = new Utilidades();
    Phrase phrase = new Phrase();
    System.out.print("Insira uma frase: ");
    phrase.addPhrase();
    System.out.println(phrase.getPhrase());
    boolean containsPalavrao = phrase.Moderar(phrase.getPhrase());
    System.out.println(containsPalavrao);
  }
}
