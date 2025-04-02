import java.util.HashMap;
import java.util.Scanner;
import java.util.Map;

public class ShoppingCart {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, double[]> cart = new HashMap<>();
        for (int i = 0; i < 5; i++) {
            System.out.println("请输入第" + (i+1) + "本书的名称、单价和数量（用空格分隔）：");
            String name = scanner.next();
            double price = scanner.nextDouble();
            int quantity = scanner.nextInt();
            cart.put(name, new double[]{price, quantity});
        }
        scanner.close();
        double total = getSum(cart);
        System.out.println("购物车总价为：" + total);
    }

    public static double getSum(HashMap<String, double[]> books) {
        double sum = 0;
        for (Map.Entry<String, double[]> entry : books.entrySet()) {
            double[] info = entry.getValue();
            sum += info[0] * info[1];
        }
        return sum;
    }
}