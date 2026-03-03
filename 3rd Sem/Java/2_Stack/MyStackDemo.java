import java.util.Scanner;

public class MyStackDemo {
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter The Max Size of the stack: ");
        int maxSize = sc.nextInt();
        Stack stack = new Stack(maxSize);

        while (true) {

            System.out.println("------Stack------\n1.push\n2.pop\n3.display\n4.peek\n5.Exit\n-----------------\n");
            System.out.print("Enter Your Choice: ");
            int choice = sc.nextInt();
            
            switch (choice) {
                case 1:
                    stack.push(sc);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display();
                    break;
                case 4: 
                    stack.peek();
                    break;
                case 5:
                    sc.close();
                    System.out.println("\nProgram Exiting......\n");
                    System.exit(0);
                default:
                    System.out.println("Invalid Choice Retry");
                    break;
            }

        }

    }
}
