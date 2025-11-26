class Outer {
    int outerVar = 10;

    // Inner class
    class Inner {
        void innerMethod() {
            System.out.println("Inner class accessing outerVar: " + outerVar);
        }
    }

    // Static nested class
    static class Nested {
        void nestedMethod() {
            System.out.println("Static nested class method");
        }
    }
}

public class Student {

    public static void main(String[] args) {
        // Create instance of outer class
        Outer outer = new Outer();

        // Create instance of inner class using outer instance
        Outer.Inner inner = outer.new Inner();
        inner.innerMethod();

        // Create instance of static nested class without outer instance
        Outer.Nested nested = new Outer.Nested();
        nested.nestedMethod();
    }
}
