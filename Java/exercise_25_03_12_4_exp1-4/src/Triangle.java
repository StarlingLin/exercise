public class Triangle {
    Point a;
    Point b;
    Point c;
    public Triangle(Point a, Point b, Point c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }
    public double area() {
        return 0.5 * Math.abs(a.x * (b.y-c.y)+ b.x * (c.y-a.y)+ c.x * (a.y-b.y));
    }
}
