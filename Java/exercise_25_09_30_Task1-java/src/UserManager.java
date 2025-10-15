import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;

class User {
    public String name;
    public int age;
    public User(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

public class UserManager {
    private static volatile UserManager instance;
    private final List<User> users;

    private UserManager() {
        users = new ArrayList<>();
    }

    public static UserManager getInstance() {
        if (instance == null) {
            synchronized (UserManager.class) {
                if (instance == null) {
                    instance = new UserManager();
                }
            }
        }
        return instance;
    }

    public void addUser(String name, int age) {
        synchronized (this) {
            users.add(new User(name, age));
        }
    }

    public void removeUser(String name) {
        synchronized (this) {
            Iterator<User> it = users.iterator();
            while (it.hasNext()) {
                User u = it.next();
                if (u.name.equals(name)) {
                    it.remove();
                    break;
                }
            }
        }
    }

    public void listAll(java.util.function.Consumer<User> consumer) {
        synchronized (this) {
            for (User u : users) {
                consumer.accept(u);
            }
        }
    }
}