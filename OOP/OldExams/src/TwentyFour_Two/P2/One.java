package TwentyFour_Two.P2;

class Livro {
  String titulo, autor, ISBN;
  int ano;

  public String getTitulo() {
    return titulo;
  }

  public String getAutor() {
    return autor;
  }

  public String getISBN() {
    return ISBN;
  }

  public int getAno() {
    return ano;
  }

  public void setTitulo(String titulo) {
    this.titulo = titulo;
  }

  
  public void setAutor(String autor) {
    this.autor = autor;
  }

  
  public void setISBN(String ISBN) {
    this.ISBN = ISBN;
  }

  
  public void setAno(int ano) {
    this.ano = ano;
  }

  public Livro(String ISBN) {
    setISBN(ISBN);
  }

  public Livro(String titulo, String autor, String ISBN, int ano) {
    setTitulo(titulo);
    setISBN(ISBN);
    setAutor(autor);
    setAno(ano);
  }
}

class LivroDeLivraria extends Livro {
  boolean vendido;

  public boolean getVendido() {
    return vendido;
  }

  public void setVendido(boolean vendido) {
    this.vendido = vendido;
  }

  public LivroDeLivraria() {
    super(" ");
  }
}

class LivroDeBiblioteca {
  
}

public class One {
  
}
