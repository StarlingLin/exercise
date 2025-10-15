public class Main {
    public static void main(String[] args) {
        UserManager mgr = UserManager.getInstance();
        mgr.addUser("����", 18);
        mgr.addUser("����", 19);
        mgr.addUser("����", 18);
        mgr.removeUser("����");
        mgr.addUser("����", 20);
        mgr.listAll(u -> System.out.println(u.name + " " + u.age));
    }
}