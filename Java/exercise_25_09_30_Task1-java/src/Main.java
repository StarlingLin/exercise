public class Main {
    public static void main(String[] args) {
        UserManager mgr = UserManager.getInstance();
        mgr.addUser("张三", 18);
        mgr.addUser("李四", 19);
        mgr.addUser("王五", 18);
        mgr.removeUser("李四");
        mgr.addUser("赵六", 20);
        mgr.listAll(u -> System.out.println(u.name + " " + u.age));
    }
}