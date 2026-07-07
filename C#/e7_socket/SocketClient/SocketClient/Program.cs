using System;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        TcpClient client = new TcpClient();
        client.Connect("127.0.0.1", 9000);
        Console.WriteLine("已连接到服务器。");
        NetworkStream stream = client.GetStream();
        string message = "哈基米！";
        byte[] data = Encoding.UTF8.GetBytes(message);
        stream.Write(data, 0, data.Length);
        Console.WriteLine("客户端发送消息：" + message);
        byte[] buffer = new byte[1024];
        int length = stream.Read(buffer, 0, buffer.Length);
        string response = Encoding.UTF8.GetString(buffer, 0, length);
        Console.WriteLine("客户端收到回复：" + response);
        stream.Close();
        client.Close();
    }
}