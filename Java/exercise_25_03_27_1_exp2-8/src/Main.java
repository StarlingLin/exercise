public class Main {
    public static void main(String[] args) {
        Manager manager = new Manager("经理A", 1001, 8000, 2000);
        Developer developer = new Developer("开发B", 1002, 6000, 10);
        manager.displayInfo();
        System.out.println();
        developer.displayInfo();
    }
}
