/*
Experiment 5 : Develop a JAVA program to create a class named shape.
 Create three sub classes namely: circle, triangle and square, each class has two member functions named draw () and erase (). 
 Demonstrate polymorphism concepts by developing suitable methods, defining member data and main program.
*/

abstract class Shape {

    public void draw() {
        System.out.println("Drawing a shape");
    }

    public void erase() {
        System.out.println("Erasing a shape");
    }

}


class Circle extends Shape {

    @Override
    public void draw() {
        System.out.println("Drawing a circle");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a circle");
    }

}


class Triangle extends Shape {

    @Override
    public void draw() {
        System.out.println("Drawing a triangle");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a triangle");
    }

}


class Square extends Shape {

    @Override
    public void draw() {
        System.out.println("Drawing a square");
    }

    @Override
    public void erase() {
        System.out.println("Erasing a square");
    }
}

public class Poly {
    public static void main(String[] args) {

        Shape circle = new Circle();
        Shape triangle = new Triangle();
        Shape square = new Square();

        circle.draw();
        circle.erase();

        triangle.draw();
        triangle.erase();

        square.draw();
        square.erase();
    }
}