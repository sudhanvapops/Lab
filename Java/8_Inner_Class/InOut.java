class Outer {

    void display(){
        System.out.println("Outer Class Display");
    }

    class Inner {

        void display(){
            System.out.println("Inner Class Display");
        }

    }
}


public class InOut {
    
    public static void main(String[] args) {
        
        Outer out = new Outer();
        out.display();

        Outer.Inner in = out.new Inner();
        in.display();

    }

}
