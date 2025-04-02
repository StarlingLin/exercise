class Student {
    private int id;
    private String name;
    private int age;
    private double score;

    public Student(int id, String name, int age, double score) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.score = score;
    }

    public void display() {
        System.out.println("学号: " + id);
        System.out.println("姓名: " + name);
        System.out.println("年龄: " + age);
        System.out.println("成绩: " + score);
    }

    public boolean isPass() {
        return score >= 60;
    }

    public static void main(String[] args) {
        Student student1 = new Student(1001, "张三", 20, 85.5);
        Student student2 = new Student(1002, "李四", 22, 58.0);
        student1.display();
        System.out.println("是否及格: " + student1.isPass());
        System.out.println();
        student2.display();
        System.out.println("是否及格: " + student2.isPass());
    }
}
