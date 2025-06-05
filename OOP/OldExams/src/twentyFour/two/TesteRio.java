package twentyFour.two;

public class TesteRio {
  public static void teste1(Rio r2, Rio r1) {
    r1.setOrigem("Mississippi");
    r1 = r2;
    r1.setOrigem("Ganges");
    r2 = r1;
    r2.setOrigem("Yangtzé");
  }

  public static void teste2(int x, int a, Rio rio) {
    int a_local = 61;
    int x_local = 114;
    rio.setOrigem("Tâmisa");
    Rio rio_novo = new Rio();
    rio_novo.volumeAgua = 55;
    rio_novo.totalRios = 86;
  }

  public static Rio teste3(Rio r2) {
    r2 = new Rio();
    r2.setOrigem("Mekong");
    return r2;
  }

  public static void main(String[] args) {
    Rio r1 = new Rio();
    r1.setOrigem("Amazônia");
    Rio r2 = new Rio();
    Rio r3 = new Rio();
    r2.setOrigem("Nilo");
    teste1(r1, r2);
    System.out.println(r1.getOrigem());
    System.out.println(r2.getOrigem());
    int x = 32;
    r1.volumeAgua = 11;
    r1.volumeAgua = r2.volumeAgua;
    System.out.println(x);
    teste2(r1.volumeAgua, x, r1);
    System.out.println(r1.volumeAgua);
    System.out.println(x);
    System.out.println(r1.volumeAgua);
    System.out.println(r1.totalRios);
    teste3(r2);
    System.out.println(r2.getOrigem());
    System.out.println(r2.volumeAgua);
    r3 = teste3(r2);
    r3.setOrigem("Danúbio");
    System.out.println(r2.getOrigem());
  }
}