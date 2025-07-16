package OOP.LearningStuff;

import java.util.Set;
import java.util.HashSet;



public class set {
  public static void main(String[] args) {
    Set<Integer> mySet = new HashSet<Integer>();
    mySet.add(10);
    mySet.add(20);
    mySet.add(30);
    mySet.add(10); // duplicated number
    System.out.println(mySet.size()); // 3
    System.out.println(mySet); // out: [20, 10, 30]. why not [10, 20, 30]?
  }
}
