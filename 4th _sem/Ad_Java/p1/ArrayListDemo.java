// Implement a java program to demonstrate creating an ArrayList, adding elements, removing elements,
// sorting elements of ArrayList. Also illustrate the use of toArray() method.

import java.util.ArrayList;
import java.util.Collections;

public class ArrayListDemo {

    public static void print(String s){
        System.out.println(s);
    }

    public static void main(String[] args) {

        // Creating an ArrayList
        ArrayList<String> list = new ArrayList<>();

        // Adding elements
        list.add("Banana");
        list.add("Apple");
        list.add("Mango");
        list.add("Orange");

        print("Original List:");
        print(""+list);

        // Removing an element
        list.remove("Mango");   // remove by value
        print("\nAfter Removing 'Mango':");
        print(""+list);

        // Sorting elements
        Collections.sort(list);
        print("\nAfter Sorting:");
        print(""+list);

        // Using toArray() method
        Object[] arr = list.toArray();

        print("\nArray elements using toArray():");
        for (Object obj : arr) {
            print(""+obj);
        }
    }
}
