import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Point[] p = new Point[3];
        System.out.print("输入点坐标：");
        Scanner sc = new Scanner(System.in);
        for (int i = 0; i < 3; i++) {
        int a = sc.nextInt();
        int b = sc.nextInt();
        p[i] = new Point(a, b);
        }
        Triangle t = new Triangle(p[0], p[1], p[2]);
        System.out.println(t.area());
    }
}