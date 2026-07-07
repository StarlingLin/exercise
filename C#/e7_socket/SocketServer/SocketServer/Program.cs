using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        TcpListener listener = new TcpListener(IPAddress.Loopback, 9000);

        listener.Start();

        Console.WriteLine("服务器已启动，等待客户端连接...");

        TcpClient client = listener.AcceptTcpClient();

        Console.WriteLine("客户端已连接。");

        NetworkStream stream = client.GetStream();

        byte[] buffer = new byte[1024];
        int length = stream.Read(buffer, 0, buffer.Length);

        string message = Encoding.UTF8.GetString(buffer, 0, length);

        Console.WriteLine("服务器收到消息：" + message);

        string reply = "哈牛魔啊。";
        byte[] replyBytes = Encoding.UTF8.GetBytes(reply);

        stream.Write(replyBytes, 0, replyBytes.Length);

        stream.Close();
        client.Close();
        listener.Stop();

        Console.WriteLine("服务器已关闭。");
    }
}