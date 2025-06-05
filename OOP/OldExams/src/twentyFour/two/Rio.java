package twentyFour.two;

public class Rio {
  private String origem;
  public int volumeAgua;
  public static int totalRios;

  public String getOrigem() {
    return origem;
  }

  public void setOrigem(String origem) {
    this.origem = origem;
  }

  public Rio() {
    volumeAgua++;
    ++totalRios;
  }
}

