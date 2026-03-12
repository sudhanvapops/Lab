import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Random;

public class TensPlaceSortExample {

    public static void main(String[] args) {

        // Given range
        int start = 10;
        int end = 100;

        Random r = new Random();
        ArrayList<Integer> list = new ArrayList<>();

        // Generate 15 random numbers
        for (int i = 0; i < 30; i++) {

            int num = r.nextInt(end - start + 1) + start;

            // Check if number is multiple of 2 and 5
            if (num % 2 == 0 && num % 5 == 0) {
                list.add(num);
            }
        }

        System.out.println("Multiples of 2 and 5:");
        System.out.println(list);

        // Sort based on tens place using Comparator
        Collections.sort(list, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {

                int tensA = (a / 10) % 10;   // get tens digit
                int tensB = (b / 10) % 10;

                return tensA - tensB;  // ascending order
            }
        });

        System.out.println("After Sorting by Tens Place:");
        System.out.println(list);
    }
} 

