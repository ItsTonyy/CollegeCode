import java.util.List;

interface Comestivel {
  public void comer();
}

class Biscoito {
  public static String id, cor;
  public int preco;
  public Biscoito(String id) {
    this.id = id;
  }
}

class utils {
  public static boolean existe(List<Biscoito> x, Biscoito y) {
    return x.contains(Biscoito.id);
  }
}

public class Main {
  public static void main(String[] args) {

  }
}