using System;
using System.IO;
using System.Net;
using System.Text;

class Program
{
    static void Main()
    {
        string url = "https://www.example.com/";
        WebRequest request = WebRequest.Create(url);
        WebResponse response = request.GetResponse();
        Stream dataStream = response.GetResponseStream();
        StreamReader reader = new StreamReader(dataStream, Encoding.UTF8);
        string responseFromServer = reader.ReadToEnd();
        Console.WriteLine(responseFromServer);
        reader.Close();
        response.Close();
    }
}