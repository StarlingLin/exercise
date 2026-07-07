using System;
using System.IO;
using System.Net;
using System.Text;

class Program
{
    static void Main()
    {
        string url = "https://httpbin.org/post";
        WebRequest request = WebRequest.Create(url);
        request.Method = "POST";
        string postData = "name=Starling&message=HelloWebRequest";
        byte[] byteArray = Encoding.UTF8.GetBytes(postData);
        request.ContentType = "application/x-www-form-urlencoded";
        request.ContentLength = byteArray.Length;
        Stream dataStream = request.GetRequestStream();
        dataStream.Write(byteArray, 0, byteArray.Length);
        dataStream.Close();
        WebResponse response = request.GetResponse();
        Console.WriteLine("Response status:");
        Console.WriteLine(((HttpWebResponse)response).StatusDescription);
        dataStream = response.GetResponseStream();
        StreamReader reader = new StreamReader(dataStream);
        string responseFromServer = reader.ReadToEnd();
        Console.WriteLine("Response content:");
        Console.WriteLine(responseFromServer);
        reader.Close();
        dataStream.Close();
        response.Close();
    }
}