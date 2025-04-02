import java.util.InputMismatchException;
import java.util.Scanner;

public class SumIntegers {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int sum = 0;
        System.out.print("Integers: ");
        while (true)
        {
            try {
                int num = sc.nextInt();
                if (num == 999) {
                    break;
                }
                sum += num;
            } catch (InputMismatchException e) {
                sc.next();
            }
        }
        System.out.println("Sum: " + sum);
        sc.close();
    }
}