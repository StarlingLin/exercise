using System;
using System.Net;
using System.Net.Sockets;
using System.Text;

class Program
{
    static void Main()
    {
        int port = 9000;
        UdpClient udpReceiver = new UdpClient(port);
        Console.WriteLine("UDP接收端启动，监听端口：" + port);
        Console.WriteLine("等待接收广播");
        IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);
        while (true)
        {
            byte[] receivedBytes = udpReceiver.Receive(ref remoteEndPoint);
            string message = Encoding.UTF8.GetString(receivedBytes);
            Console.WriteLine("收到" + remoteEndPoint.Address + ":" + remoteEndPoint.Port + "的消息：");
            Console.WriteLine(message);
            Console.WriteLine();
        }
    }
}