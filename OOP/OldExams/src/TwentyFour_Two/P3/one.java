package OOP.OldExams.src.TwentyFour_Two.P3;

import java.util.List;
import java.util.Map;
import java.util.Objects;
import java.util.Set;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;

public class one {
  class Veiculo {
    private String placa, modelo;
    private double precoDiaria;

     public Veiculo(String placa) {
      this.placa = placa;
    }

    public void setPlaca(String placa) {
      this.placa = placa;
    }

    public void setModelo(String modelo) {
      this.modelo = modelo;
    }

    public void setPrecoDiaria(double precoDiaria) {
      this.precoDiaria = precoDiaria;
    }

    @Override
    public boolean equals(Object o) {
      if(o == null) return false;

      Veiculo veiculo = (Veiculo) o;

      return Objects.equals(placa, veiculo.placa);
    }

    @Override
    public String toString() {
      return this.placa + " " + this.modelo + " " + this.precoDiaria;
    }
  }

  class locadoraUtils {
    public static boolean existe(List<Veiculo> lista, Veiculo veiculo) {
      return lista.contains(veiculo);
    }

    public Map processaDados(Set conjuntoVeiculos) throws Exception {
      Map<String, Veiculo> mapaVeiculos = new HashMap<String, Veiculo>();
      Iterator it = conjuntoVeiculos.iterator();
      while(it.hasNext()) {
        Veiculo veiculo;

        String conjuntoAtual = (String) it.next();
        String[] conjuntoFiltrado = conjuntoAtual.split("#");

        String tipo = conjuntoFiltrado[3];
        String placa = conjuntoFiltrado[0];
        
        if(tipo.equals("C")) {
          veiculo = new Carro(placa);
        } else if (tipo.equals("M")) {
          veiculo = new Moto(placa);
        } else {
          throw new Exception("Tipo de veiculo inválido");
        } 

        veiculo.setModelo(conjuntoFiltrado[1]);

        Double precoDiariaEmNumero = Double.parseDouble(conjuntoFiltrado[2]);
        veiculo.setPrecoDiaria(precoDiariaEmNumero);

        mapaVeiculos.put(placa, veiculo);
      }
      return mapaVeiculos;
    }
  }

  class Carro extends Veiculo {
    public Carro(String placa) {
      super(placa);
    }
  }

  class Moto extends Veiculo {
    public Moto(String placa) {
      super(placa);
    }
  }

  class SistemaLocadora {
    Scanner scanner = new Scanner(System.in);
    System.out.println("Insira a placa");
    String placa = scanner.nextLine();
    System.out.println("Insira o modelo");
    String modelo = scanner.nextLine();
    System.out.println("Insira o preco");
    String preco = scanner.nextLine();
    System.out.println("Insira o precoDiaria");
    Double precoDiaria = scanner.nextDouble();
    System.out.println("Insira o tipo");
    String tipo = scanner.nextLine();

    
  }
}
