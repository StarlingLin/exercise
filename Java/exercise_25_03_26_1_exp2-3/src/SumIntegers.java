import java.util.InputMismatchException;
import java.util.Scanner;

public class SumIntegers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        System.out.print("Integers: ");
        while (true) {
            try {
                int num = sc.nextInt();
                if (num == 999) {
                    break;
                }
                if (num < 0) {
                    throw new IllegalArgumentException("No Negative");
                }
                sum += num;
            } catch (InputMismatchException e) {
                sc.next();
            } catch (IllegalArgumentException e) {
                System.out.println("No Negative");
            }
        }
        System.out.println("Sum: " + sum);
        sc.close();
    }
}