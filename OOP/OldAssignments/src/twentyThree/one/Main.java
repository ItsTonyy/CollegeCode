package twentyThree.one;

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

// didn't finished the first question, the answer (which is not fully here) is quite complex so something might be wrong