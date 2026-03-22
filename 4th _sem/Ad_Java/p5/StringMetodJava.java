// 5. Implement a java program to illustrate the use of different types of character extraction, string comparison, string search and string modification methods. 

public class StringMetodJava {

    public static void print(String s) {
        System.out.println(s);
    }

    public static void main(String[] args) {

        String s1 = "Java Programming";
        String s2 = "Java";

        // Character Extraction
        print("Character at index 2: " + s1.charAt(2));
        print("Substring: " + s1.substring(5, 16));

        // String Comparison
        print("Equals: " + s1.equals(s2));
        print("CompareTo: " + s1.compareTo(s2));

        // String Search
        print("Index of 'Pro': " + s1.indexOf("Pro"));
        print("Last index of 'a': " + s1.lastIndexOf('a'));

        // String Modification
        print("Replace: " + s1.replace("Java", "Advanced Java"));
        print("Upper Case: " + s1.toUpperCase());
    }
}