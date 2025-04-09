import java.sql.*;

public class EmployeeManager {
    static final String JDBC_DRIVER = "org.apache.derby.jdbc.EmbeddedDriver";
    static final String DB_URL = "jdbc:derby:myDB;create=true";

    public static void main(String[] args) {
        try {
            Class.forName(JDBC_DRIVER);
            initializeDatabase();
            showMaleEmployees();
            insertNewEmployee();
            updateAndShowEmployee();
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            shutdownDerby();
        }
    }

    private static void initializeDatabase() throws SQLException {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {

            boolean tableExists = conn.getMetaData().getTables(null, null, "EMPLOYEE", null).next();
            if (tableExists) {
                stmt.executeUpdate("DROP TABLE employee");
                System.out.println("表 employee 已删除");
                tableExists = false;
            }

            if (!tableExists) {
                String createSQL = "CREATE TABLE employee ("
                        + "sno VARCHAR(4) PRIMARY KEY, "
                        + "name VARCHAR(8), "
                        + "sex VARCHAR(2), "
                        + "salary FLOAT)";
                stmt.executeUpdate(createSQL);
                System.out.println("表 employee 已创建");

                String insertSQL = "INSERT INTO employee VALUES "
                        + "('1001', '张强', '男', 675.20),"
                        + "('1004', '李香', '女', 842.00),"
                        + "('1007', '王大山', '男', 765.00),"
                        + "('1010', '赵玉花', '女', 690.00)";
                stmt.executeUpdate(insertSQL);
                System.out.println("初始数据插入成功");
            }
        }
    }

    private static void showMaleEmployees() throws SQLException {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {

            ResultSet rs = stmt.executeQuery("SELECT * FROM employee WHERE sex='男'");
            System.out.println("\n所有男员工记录：");
            while (rs.next()) {
                printEmployee(rs);
            }
            System.out.println("----------------------");
        }
    }

    private static void insertNewEmployee() throws SQLException {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {

            ResultSet rs = stmt.executeQuery("SELECT * FROM employee WHERE sno = '2017'");
            if (!rs.next()) {
                int rows = stmt.executeUpdate(
                        "INSERT INTO employee VALUES ('2017', '邢雪花', '女', 650)");
                System.out.println("\n插入" + rows + "条记录成功");
            } else {
                System.out.println("\n记录已存在，跳过插入");
            }
        }
    }

    private static void updateAndShowEmployee() throws SQLException {
        try (Connection conn = DriverManager.getConnection(DB_URL);
             Statement stmt = conn.createStatement()) {
            int rows = stmt.executeUpdate(
                    "UPDATE employee SET salary=900 WHERE sno='2017'");
            System.out.println("\n更新" + rows + "条记录");

            ResultSet rs = stmt.executeQuery(
                    "SELECT * FROM employee WHERE sno='2017'");
            System.out.println("更新后的记录：");
            while (rs.next()) {
                printEmployee(rs);
            }
        }
    }

    private static void printEmployee(ResultSet rs) throws SQLException {
        System.out.printf("工号: %s 姓名: %-3s 性别: %s 工资: %.2f%n",
                rs.getString("sno"),
                rs.getString("name"),
                rs.getString("sex"),
                rs.getFloat("salary"));
    }

    private static void shutdownDerby() {
        try {
            DriverManager.getConnection("jdbc:derby:;shutdown=true");
        } catch (SQLException e) {
            if (e.getErrorCode() == 50000 && "XJ015".equals(e.getSQLState())) {
                System.out.println("数据库正常关闭");
            } else {
                e.printStackTrace();
            }
        }
    }
}
