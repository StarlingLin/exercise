using System;
using System.Text.Json;

public class WeatherForecast
{
    public DateTime Date
    {
        get;
        set;
    }

    public int TemperatureCelsius
    {
        get;
        set;
    }

    public string? Summary
    {
        get;
        set;
    }
}

class Program
{
    static void Main()
    {
        WeatherForecast weather = new WeatherForecast
        {
            Date = DateTime.Now,
            TemperatureCelsius = 25,
            Summary = "Hot"
        };

        // 序列化
        JsonSerializerOptions options = new JsonSerializerOptions
        {
            WriteIndented = true
        };

        string jsonString = JsonSerializer.Serialize(weather, options);

        Console.WriteLine("序列化后的 JSON：");
        Console.WriteLine(jsonString);

        Console.WriteLine();

        // 反序列化
        WeatherForecast? result =
            JsonSerializer.Deserialize<WeatherForecast>(jsonString);

        Console.WriteLine("反序列化后的对象：");
        Console.WriteLine($"Date: {result?.Date}");
        Console.WriteLine($"TemperatureCelsius: {result?.TemperatureCelsius}");
        Console.WriteLine($"Summary: {result?.Summary}");
    }
}