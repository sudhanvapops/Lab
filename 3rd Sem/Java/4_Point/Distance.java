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
        int[] a = { this.x, this.y };
        return a;
    }

    @Override
    public String toString() {
        return "( x: " + x + ", y: " + y + " )";
    }

    public double distance(int x, int y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }

    public double distance(MyPoint aotherPoint) {
        return Math.sqrt(Math.pow(this.x - aotherPoint.x, 2) + Math.pow(this.y - aotherPoint.y, 2));
    }

    public double distance() {
        return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
    }

}

public class Distance {

    public static void main(String[] args) {

        MyPoint p1 = new MyPoint();
        MyPoint p2 = new MyPoint(3, 4);

        System.out.println("Point 1 (default constructor): " + p1);
        System.out.println("Point 2 (overloaded constructor): " + p2);

        p1.setXY(6, 8);
        System.out.println("Point 1 after setXY (6, 8): " + p1);

        int cords[] = p2.getXY();
        System.out.println("Coordinates of Point 2: (" + cords[0] + ", " + cords[1] + ")");

        double distanceToPoint = p1.distance(10,10);
        System.out.printf("Distance from Point 1 to (10, 10): %.4f%n",distanceToPoint);

        double distanceBetweenPoints = p1.distance(p2);
        System.out.printf("Distance from Point 1 to Point 2: %.4f%n" ,distanceBetweenPoints);

        double distanceToOrigin = p1.distance();
        System.out.printf("Distance from Point 1 to the origin: %.4f%n", distanceToOrigin);
    }
}
