/*
Exp 9. Develop a JAVA program to raise a custom exception for 
Division By Zero using try, catch, throw and finally.
*/

// Custom Exception Class
class DivisionByZeroException extends Exception {
    public DivisionByZeroException(String message) {
        super(message);
    }
}

public class Exp {

    public static void main(String[] args) {
        try {
            int result = divide(10, 10);
            System.out.println("Result: " + result);
        } 
        catch (DivisionByZeroException e) {
            System.out.println("Exception caught: " + e.getMessage());
        } 
        finally {
            System.out.println("Finally block executed.");
        }
    }

    // Method that may throw the custom exception
    static int divide(int numerator, int denominator) throws DivisionByZeroException {
        try {
            if (denominator == 0)
                throw new DivisionByZeroException("Division by zero is not allowed.");
            
            return numerator / denominator;
        } 
        catch (ArithmeticException e) {
            throw new DivisionByZeroException("Arithmetic Exception: " + e.getMessage());
        }
    }
}
