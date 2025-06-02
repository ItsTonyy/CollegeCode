package twentyFour.two;

class Planta {
  private String id;
  private String nome;
  private double tamanho;

  public Planta(String id) {
    this.id = id;
  }

  @Override
  public String toString() {
    return "ID: " + id + ", Nome: " + nome + ", Tamanho: " + tamanho + "cm";
  }
}

public class Two {
  public static void main(String[] args) {

  }
}
