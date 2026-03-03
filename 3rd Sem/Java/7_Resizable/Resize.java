interface Resizeable {
    void resizeHeight(int height);
    void resizeWidth(int width);
}

class Rectangle implements Resizeable {

    private int height;
    private int width;

    public Rectangle(int height, int width) {
        this.height = height;
        this.width = width;
    }

    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }

    @Override
    public void resizeHeight(int height) {
        this.height = height;
    }

    @Override
    public void resizeWidth(int width) {
        this.width = width;
    }

}

public class Resize {

    public static void print(String s){
        System.out.println(s);
    }

    public static void main(String[] args) {

        Rectangle rec = new Rectangle(10,5);

        print("Initial Rectangle Width: "+rec.getWidth());
        print("Initial Rectangle Height: "+rec.getHeight());

        rec.resizeWidth(15);
        rec.resizeHeight(8);

        print("Resized Rectangle Width: "+rec.getWidth());
        print("Resized Rectangle Height: "+rec.getHeight());

    }

}
