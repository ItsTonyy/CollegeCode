package twentyFour.two;

import java.util.ArrayList;
import java.util.List;

class Planta {
  private String id;
  private String nome;
  private double tamanho;

  public Planta(String id) {
    this.id = id;
  }

  public String getId() {
    return id;
  }

  public String getNome() {
    return nome;
  }

  public double getTamanho() {
    return tamanho;
  }

  @Override
  public String toString() {
    return "ID: " + id + ", Nome: " + nome + ", Tamanho: " + tamanho + "cm";
  }
}

class Briofita extends Planta {
  public Briofita(String id) {
    super(id);
  }

  @Override
  public String toString() {
    return "[Briofita] " + super.toString();
  }
}

class Pteridofita extends Planta {
  public Pteridofita(String id) {
    super(id);
  }

  @Override
  public String toString() {
    return "[Pteridofita] " + super.toString();
  }
}

class Utils {
  public static boolean existe(List lista, Planta planta) {
    return lista.contains(planta);
  }

  public static Planta[] ordena(List lista) {
    Planta[] plantasArray = lista.toArray(new Planta[0])

    for (int i = 0; i < lista.size(); i++) {
      for (int j = i + 1; j < lista.size(); j++) {

      }
    }
  }
}

public class Two {
  public static void main(String[] args) {

  }
}
