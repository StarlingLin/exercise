public class Main {
    public static void main(String[] args) {
        // Integer a = new Integer(114514); 已经在JDK9弃用
        // Integer a = Integer.valueOf(114514); 不必要的装箱
        Integer a = 114514;
        System.out.println(a);
        String s = Integer.toString(a);
        System.out.println(s);
        Integer b = Integer.valueOf(s);
        System.out.println(b);
        Integer c = Integer.parseInt(s);
        System.out.println(c);
        s += "abc";
        Integer d = 1919810;
        System.out.println(d);
        System.out.println(d.equals(c));
        System.out.println(c.compareTo(d));
        System.out.println(Integer.toBinaryString(a));
    }
}