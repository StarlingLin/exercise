import java.io.*;
import java.net.*;

public class Client
{
    public static void main(String[] args)
    {
        final String HOST = "localhost";
        final int PORT = 1888;

        try (Socket socket = new Socket(HOST, PORT))
        {
            PrintWriter out = new PrintWriter(
                    socket.getOutputStream(), true);

            BufferedReader in = new BufferedReader(
                    new InputStreamReader(socket.getInputStream()));
            String message = "地瓜、地瓜，我是土豆，请回答！";
            out.println(message);
            System.out.println("发送到服务器：" + message);
            String response = in.readLine();
            System.out.println("收到服务器回复：" + response);
            in.close();
            out.close();
        }
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}
