/*
Exp. 7:
Develop a JAVA program to create an interface Resizable with methods
resizeWidth(int width) and resizeHeight(int height) that allow an object
to be resized. Create a class Rectangle that implements the Resizable
interface and implements the resize methods.
*/

// Interface Resizable with two resize methods
interface Resizeable {
    void resizeWidth(int width);
    void resizeHeight(int height);
}

// Rectangle class implementing the Resizeable interface
class Rectangle implements Resizeable {

    private int width;
    private int height;

    // Constructor for Rectangle
    public Rectangle(int width, int height) {
        this.width = width;
        this.height = height;
    }

    // Getter method for width
    public int getWidth() {
        return width;
    }

    // Getter method for height
    public int getHeight() {
        return height;
    }

    // Implementation of resizeWidth method
    @Override
    public void resizeWidth(int width) {
        this.width = width;
    }

    // Implementation of resizeHeight method
    @Override
    public void resizeHeight(int height) {
        this.height = height;
    }
}

// Main class
public class Inter {
    public static void main(String[] args) {

        // Create Rectangle object
        Rectangle rectangle = new Rectangle(10, 5);

        // Display initial width and height
        System.out.println("Initial Width: " + rectangle.getWidth());
        System.out.println("Initial Height: " + rectangle.getHeight());

        // Resize the rectangle
        rectangle.resizeWidth(15);
        rectangle.resizeHeight(8);

        // Display resized width and height
        System.out.println("Resized Width: " + rectangle.getWidth());
        System.out.println("Resized Height: " + rectangle.getHeight());
    }
}
