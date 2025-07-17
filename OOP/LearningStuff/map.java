package OOP.LearningStuff;

import java.util.HashMap;
import java.util.Map;

public class map {
  public static void main(String[] args) {
  // Map<E> map = new Type();
    Map<String, Integer> people = new HashMap<String, Integer>();
    people.put("Lionel Messi", 38);
    people.put("Lamine Yamal", 18);
    people.put("Neymar jr", 35);

    System.out.println(people);

    System.out.println();

    System.out.println(people.get("Neymar jr")); //35
  }
}
