import java.util.ArrayList;
import java.util.Collections;

public class ArrayListDemo {
    public static void main(String[] args) {

        // Creating an ArrayList
        ArrayList<String> list = new ArrayList<>();

        // Adding elements
        list.add("Banana");
        list.add("Apple");
        list.add("Mango");
        list.add("Orange");

        System.out.println("Original List:");
        System.out.println(list);

        // Removing an element
        list.remove("Mango");   // remove by value
        System.out.println("\nAfter Removing 'Mango':");
        System.out.println(list);

        // Sorting elements
        Collections.sort(list);
        System.out.println("\nAfter Sorting:");
        System.out.println(list);

        // Using toArray() method
        Object[] arr = list.toArray();

        System.out.println("\nArray elements using toArray():");
        for (Object obj : arr) {
            System.out.println(obj);
        }
    }
}
