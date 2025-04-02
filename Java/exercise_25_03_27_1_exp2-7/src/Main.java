public class Main {
    public static void main(String[] args) {
        Shape shape1 = new Circle(5.0);
        Shape shape2 = new Rectangle(4.0, 6.0);
        shape1.draw();
        System.out.println("圆形面积: " + shape1.area());
        shape2.draw();
        System.out.println("矩形面积: " + shape2.area());
    }
}