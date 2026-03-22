// Develop a program to read random numbers between a given range that are multiples of 2 and 5, sort
// the numbers according to tens place using comparator. 

import java.util.*;

public class TensPlaceSortExample {


    public static void print(String s){
        System.out.println(s);
    }

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
            if (num % 2 == 0 && num % 5 == 0) 
                list.add(num);
        }

        print("Multiples of 2 and 5:");
        print(""+list);

        // Sort based on tens place using Comparator
        Collections.sort(list, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {

                int tensA = (a / 10) % 10;   // get tens digit
                int tensB = (b / 10) % 10;

                return tensA - tensB;  // ascending order
            }
        });

        print("After Sorting by Tens Place:");
        print(""+list);
    }
} 

