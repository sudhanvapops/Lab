// 6. Implement a java program to illustrate the use of different types of StringBuffer methods

public class Sbd {

    public static void print(String s){
        System.out.println(s);
    }

    public static void main(String[] args) {

        StringBuffer sb = new StringBuffer("Java");

        // Append method
        sb.append(" Programming");
        print("Append: " + sb);

        // Insert method
        sb.insert(5, "Advanced ");
        print("Insert: " + sb);

        // Replace method
        sb.replace(5, 13, "Core ");
        print("Replace: " + sb);

        // Delete method
        sb.delete(5, 10);
        print("Delete: " + sb);

        // Reverse method
        sb.reverse();
        print("Reverse: " + sb);
    }
}
