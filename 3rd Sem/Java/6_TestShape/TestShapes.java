/* Develop a JAVA program to create an abstract class Shape with abstract methods calculateArea() 
and calculatePerimeter(). Create subclasses Circle and Triangle that extend the Shape class 
and implement the respective methods to calculate the area and perimeter of each shape. */

abstract class Shape {
    public abstract double calculateArea();
    public abstract double calculatePerimeter();
}


class Circle extends Shape {

    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double calculateArea() {
        return Math.PI * Math.pow(radius, 2);
    }

    @Override
    public double calculatePerimeter() {
        return 2 * Math.PI * radius;
    }
}


class Triangle extends Shape {

    private double side1,side2,side3;

    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    @Override
    public double calculateArea() {
        double s = (side1 + side2 + side3) / 2; // Semi-perimeter
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Area formula
    }

    @Override
    public double calculatePerimeter() {
        return side1 + side2 + side3;
    }
}


public class TestShapes {
    public static void main(String[] args) {

        Shape circle = new Circle(5);
        System.out.println("Circle:");
        System.out.println("Area: " + circle.calculateArea());
        System.out.println("Perimeter: " + circle.calculatePerimeter());

        Shape triangle = new Triangle(3, 4, 5);
        System.out.println("\nTriangle:");
        System.out.println("Area: " + triangle.calculateArea());
        System.out.println("Perimeter: " + triangle.calculatePerimeter());
    }
}
