// 4. Implement a java program to illustrate the use of different types of string class constructors.

import java.lang.String;

public class StrConsDemo {

    public static void print(String s){
        System.out.println(s);
    }

    public static void main(String[] args) {
        
        String s;
        // 1. Empty String constructor
        s = new String();
        print("s1: " + s);

        // 2. String from another string
        s = new String("Hello");
        print("s2: " + s);

        // 3. String from character array
        char ch[] = {'J','A','V','A'};
        s = new String(ch);
        print("s3: " + s);

        // 4. String from byte array
        byte b[] = {65,66,67};
        s = new String(b);
        print("s4: " + s);
    }
}
