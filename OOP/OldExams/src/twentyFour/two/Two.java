package twentyFour.two;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Planta {
  private String id;
  private String nome;
  private double tamanho;

  public Planta(String id, double tamanho) {
    this.id = id;
    this.tamanho = tamanho;
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

  @Override
  public boolean equals(Object obj) {
    if (obj instanceof Planta p) {
      return id.equals(p.id);
    }
    return false;
  }
}

class Briofita extends Planta {
  public Briofita(String id, double tamanho) {
    super(id, tamanho);
  }

  @Override
  public String toString() {
    return "[Briofita] " + super.toString();
  }
}

class Pteridofita extends Planta {
  public Pteridofita(String id, double tamanho) {
    super(id, tamanho);
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
    Planta[] plantasArray = (Planta[]) lista.toArray(new Planta[0]);

    for (int i = 0; i < lista.size(); i++) {
      for (int j = i + 1; j < lista.size(); j++) {
        if(plantasArray[j].getTamanho() > plantasArray[i].getTamanho() ) {
          Planta temp = plantasArray[j];
          plantasArray[j] = plantasArray[i];
          plantasArray[i] = temp;
        }
      }
    }
    return plantasArray;
  }
}

public class Two {
  public static void main(String[] args) {
    List<Planta> listaPlantas = new ArrayList<Planta>();

    listaPlantas.add(new Planta("1", 2.2));
    listaPlantas.add(new Planta("2", 3.3));
    listaPlantas.add(new Planta("3", 1.2));
    listaPlantas.add(new Planta("4", 5.2));


    Scanner scanner = new Scanner(System.in);
    System.out.println("Digite o ID da planta: ");
    String plantID = scanner.nextLine();
    Planta planta = new Planta(plantID, 0);

    if (Utils.existe(listaPlantas, planta)) {
      for (Planta p : listaPlantas) {
        if (p.equals(planta)) {
          System.out.println(true);
          break;
        }
      }
    } else {
      System.out.println("A planta de ID " + plantID + " não existe.");
    }
    Planta[] plantasOrdenadas = Utils.ordena(listaPlantas);

    for(Planta p : plantasOrdenadas) {
      System.out.println(p);
    }
  }
}
