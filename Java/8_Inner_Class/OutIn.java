/*
Exp 8:
Develop a JAVA program to create an outer class with a function display.
Create another class inside the outer class named Inner with a function 
called display, and call both functions in the main class.
*/

// Outer class
class Outer {

    // Method in outer class
    void display() {
        System.out.println("Outer class display");
    }

    // Inner class
    class Inner {

        // Method in inner class
        void display() {
            System.out.println("Inner class display");
        }
    }
}

// Main class
public class OutIn {

    public static void main(String[] args) {

        // Create an instance of the Outer class
        Outer outerObj = new Outer();

        // Call the display method of the outer class
        outerObj.display();

        // Create an instance of the Inner class using the outer class instance
        Outer.Inner innerObj = outerObj.new Inner();

        // Call the display method of the inner class
        innerObj.display();
    }
}
