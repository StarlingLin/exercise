using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        int port = 9000;

        using UdpClient sender = new UdpClient();

        sender.EnableBroadcast = true;

        IPEndPoint broadcastEndPoint = new IPEndPoint(
            IPAddress.Parse("192.168.1.255"),
            port
        );

        Console.WriteLine("UDP 广播发送端启动");
        Console.WriteLine("输入内容后回车广播：");

        while (true)
        {
            string message = Console.ReadLine();

            if (string.IsNullOrWhiteSpace(message))
            {
                continue;
            }

            byte[] data = Encoding.UTF8.GetBytes(message);

            sender.Send(data, data.Length, broadcastEndPoint);

            Console.WriteLine("已广播到 192.168.1.255:9000：" + message);
        }
    }
}