abstract class Shape {

    public void draw(){
        System.out.println("Drawing a Shape");
    }

    public void erase(){
        System.out.println("Errasing a Shape");
    }

    // abstract public void show();
}


class Square extends Shape {

    @Override
    public void draw() {
        System.out.println("Drawing Square");
    }

    @Override
    public void erase() {
        System.out.println("Earasing Square");
    }
    
}


class Triangle extends Shape {

    @Override
    public void draw() {
        System.out.println("Drawing Triangle");
    }

    @Override
    public void erase() {
        System.out.println("Earasing Triangle");
    }
    
}

class Circle extends Shape {

    @Override
    public void draw(){
        System.out.println("Drawing Circle");
    }

    @Override
    public void erase() {
        System.out.println("Earasing Circle");
    }
    
}

class Rectangle extends Shape{

    public void show(){
        System.out.println("This is a Rectangle");
    }
}


public class Polymorphism {

    public static void main(String[] args) {
        
        Shape circle = new Circle();
        Shape square = new Square();
        Shape triangle = new Triangle();
        Shape rectangle = new Rectangle();

        circle.draw();
        circle.erase();

        triangle.draw();
        triangle.erase();

        square.draw();
        square.erase();

        rectangle.draw();
        rectangle.erase();

        // This wont work 
        // rectangle.show();
        if (rectangle instanceof Rectangle){
            ((Rectangle) rectangle).show();
        }

    }

}
