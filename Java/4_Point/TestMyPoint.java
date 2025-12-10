class MyPoint {

    private int x;
    private int y;

    public MyPoint() {
        this.x = 0;
        this.y = 0;
    }

    public MyPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int[] getXY() {
        int a[] = { x, y };
        return a;
    }

    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public double distance(int x, int y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }

    public double distance(MyPoint another) {
        return Math.sqrt(Math.pow(this.x - another.x, 2) + Math.pow(this.y - another.y, 2));
    }

    public double distance() {
        return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
    }
}


public class TestMyPoint {
    public static void main(String[] args) {

        MyPoint point1 = new MyPoint(); // Default constructor (0, 0)
        MyPoint point2 = new MyPoint(3, 4); // Overloaded constructor (3, 4)

        System.out.println("Point 1 (default constructor): " + point1); // Expected: (0, 0)
        System.out.println("Point 2 (overloaded constructor): " + point2); // Expected: (3, 4)

        point1.setXY(6, 8);
        System.out.println("Point 1 after setXY(6, 8): " + point1); // Expected: (6, 8)

        int[] coordinates = point2.getXY();
        System.out.println("Coordinates of Point 2: (" + coordinates[0] + ", " + coordinates[1] + ")");

        double distanceToPoint = point1.distance(10, 10);
        System.out.println("Distance from Point 1 to (10, 10): " + distanceToPoint);

        double distanceBetweenPoints = point1.distance(point2);
        System.out.println("Distance from Point 1 to Point 2: " + distanceBetweenPoints);

        double distanceToOrigin = point1.distance();
        System.out.println("Distance from Point 1 to the origin: " + distanceToOrigin);
    }
}