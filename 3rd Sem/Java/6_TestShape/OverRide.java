abstract class Shape{
    abstract public double calcPeri();
    abstract public double calcArea();
}


class Triangle extends Shape {

    private double s1,s2,s3;

    public Triangle(double s1,double s2,double s3){
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }

    @Override
    public double calcArea() {
        double s = (s1 + s2 + s3) / 2;
        return Math.sqrt((s*(s-s1)*(s-s2)*(s-s3)));
    }

    @Override
    public double calcPeri() {
        return s1+s2+s3;
    }
    
}


class Circle extends Shape {

    private double r;

    public Circle(double r){
        this.r = r;
    }

    @Override
    public double calcArea(){
        return Math.PI * Math.pow(r, 2);
    }

    @Override
    public double calcPeri(){
        return 2 * Math.PI * r;
    }

}


public class OverRide{

    public static void main(String[] args) {
        
        Shape circle = new Circle(5);
        Shape triangle = new Triangle(3, 4, 5);

        System.out.println("Circle:\nArea: "
        +circle.calcArea()
        +"\nPerimeter: "+circle.calcPeri());

        System.out.println("\nTriangle:\nArea: "
        +triangle.calcArea()+
        "\nPerimeter: "+triangle.calcPeri());
    }
}