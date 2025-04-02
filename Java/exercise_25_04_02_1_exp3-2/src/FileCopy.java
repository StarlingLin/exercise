import java.io.*;

public class FileCopy {
    public static void main(String[] args) {
        try (BufferedReader reader = new BufferedReader(new FileReader("HelloWorldDemo.java"))) {
            System.out.println("文件内容:");
            String line;
            StringBuilder content = new StringBuilder();
            while ((line = reader.readLine()) != null) {
                System.out.println(line);
                content.append(line).append("\n");
            }
            try (BufferedWriter writer = new BufferedWriter(new FileWriter("HelloWorldDemo.txt"))) {
                writer.write(content.toString());
                System.out.println("\n文件已成功复制到 HelloWorldDemo.txt");
            }
        } catch (FileNotFoundException e) {
            System.err.println("错误：源文件未找到！");
        } catch (IOException e) {
            System.err.println("IO异常：" + e.getMessage());
        }
    }
}