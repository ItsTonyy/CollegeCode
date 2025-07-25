package OOP.OldExams.src.TwentyThree_One.pf;

public class One {
  abstract class Livro {
    String nome, autor;
    int ano;
    private String isbn;

    // constructor
    public Livro(int ano) {
      this.ano = ano;
    }

    public void setNome(String nome) {
      this.nome = nome;
    }

    public void setAutor(String autor) {
      this.autor = autor;
    }

    public void setAno(int ano) {
      this.ano = ano;
    }

    public void setIsbn(String isbn) {
      this.isbn = isbn;
    }

    public String getNome() {
      return nome;
    }

    public String getAutor() {
      return autor;
    }

    public int getAno() {
      return ano;
    }

    public String getIsbn() {
      return isbn;
    }

    @Override
    public boolean equals(Object o) {
      if(o instanceof Livro) {
        Livro livro = (Livro) o;
        return isbn.equals(livro.getIsbn());
      }
      return false;
    }
  }

  class LivroDeLivraria extends Livro {
    boolean vendido;

    // constructor
    public LivroDeLivraria(int ano, boolean vendido) {
      this.vendido = vendido;
      super(ano);
    }

    public void setVendido(boolean vendido) {
      this.vendido = vendido;
    } 

    public boolean getVendido() {
      return vendido;
    }

    class LivroDeBiblioteca extends Livro {
      boolean alugado;

      // constructor
      public LivroDeBiblioteca(int ano, boolean alugado) {
        this.alugado = alugado;
        super(ano);
      }

      public void setAlugado(boolean alugado) {
        this.alugado = alugado;
      }

      public boolean getAlugado() {
        return alugado;
      }
    }
  }
  

}
