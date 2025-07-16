package OOP.LearningStuff;
import java.util.ArrayList;
import java.util.Iterator;

public class iterator {
  public static void main(String[] args) {
    ArrayList<Integer> lista = new ArrayList<Integer>();
    lista.add(8);
    lista.add(9);
    lista.add(10);
    lista.add(11);
    lista.add(12);
    System.out.println(lista); // [8, 9, 10, 11, 12]
    Iterator<Integer> it = lista.iterator();
    while(it.hasNext()) {
      if(it.next() < 10) {
        it.remove();
      }
    }
    System.out.println(lista); // [10, 11, 12]
  }
}
