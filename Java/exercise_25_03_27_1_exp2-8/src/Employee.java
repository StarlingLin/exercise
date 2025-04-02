class Employee {
    protected String name;
    protected int id;
    protected double salary;

    public Employee(String name, int id, double salary) {
        this.name = name;
        this.id = id;
        this.salary = salary;
    }
    public double calculateSalary() {
        return salary;
    }
    public void displayInfo() {
        System.out.println("姓名: " + name);
        System.out.println("工号: " + id);
        System.out.println("工资: " + calculateSalary());
    }
}

class Manager extends Employee {
    private double bonus;

    public Manager(String name, int id, double salary, double bonus) {
        super(name, id, salary);
        this.bonus = bonus;
    }
    @Override
    public double calculateSalary() {
        return salary + bonus;
    }
    @Override
    public void displayInfo() {
        System.out.println("经理信息:");
        super.displayInfo();
        System.out.println("总工资: " + calculateSalary());
    }
}

class Developer extends Employee {
    private int overtimeHours;
    private static final double overtimeRate = 50.0;

    public Developer(String name, int id, double salary, int overtimeHours) {
        super(name, id, salary);
        this.overtimeHours = overtimeHours;
    }
    @Override
    public double calculateSalary() {
        return salary + (overtimeHours * overtimeRate);
    }
    @Override
    public void displayInfo() {
        System.out.println("开发者信息:");
        super.displayInfo();
        System.out.println("总工资: " + calculateSalary());
    }
}