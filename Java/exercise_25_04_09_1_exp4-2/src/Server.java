import java.io.*;
import java.net.*;

public class Server
{
    public static void main(String[] args)
    {
        final int PORT = 1888;

        try (ServerSocket serverSocket = new ServerSocket(PORT))
        {
            System.out.println("服务器启动，等待客户端连接...");
            Socket clientSocket = serverSocket.accept();
            System.out.println("客户端已连接：" + clientSocket.getInetAddress());
            BufferedReader in = new BufferedReader(
                    new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(
                    clientSocket.getOutputStream(), true);
            String clientMessage = in.readLine();
            System.out.println("收到客户端消息：" + clientMessage);
            String response = "土豆，土豆，我是地瓜，信息已收到！";
            out.println(response);
            in.close();
            out.close();
            clientSocket.close();
            System.out.println("连接已关闭。");
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
