public class ComputeTime {
    public static void main(String[] args) {
        String transportType = args[0];
        int A = Integer.parseInt(args[1]);
        int B = Integer.parseInt(args[2]);
        int C = Integer.parseInt(args[3]);

        try {
            Common transport = (Common)Class.forName(transportType).newInstance();
            double speed = transport.getSpeed(A, B, C);
            double time = 1000 / speed;

            System.out.printf("%s行驶1000公里所需的时间为：%.2f 小时\n", transportType, time);
        }
        catch (ClassNotFoundException e) {
            System.out.println("未找到类：" + transportType);
        }
        catch (InstantiationException | IllegalAccessException e) {
            System.out.println("实例化类时出错：" + e.getMessage());
        }
    }
}