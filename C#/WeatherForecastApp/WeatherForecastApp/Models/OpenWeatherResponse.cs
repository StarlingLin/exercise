using System.Collections.Generic;
using System.Text.Json.Serialization;

namespace WeatherForecastApp.Models
{
    public class OpenWeatherResponse
    {
        [JsonPropertyName("name")]
        public string CityName { get; set; } = "";

        [JsonPropertyName("weather")]
        public List<OpenWeatherInfo> Weather { get; set; } = new List<OpenWeatherInfo>();

        [JsonPropertyName("main")]
        public OpenWeatherMain Main { get; set; } = new OpenWeatherMain();

        [JsonPropertyName("cod")]
        public int Code { get; set; }
    }

    public class OpenWeatherInfo
    {
        [JsonPropertyName("main")]
        public string Main { get; set; } = "";

        [JsonPropertyName("description")]
        public string Description { get; set; } = "";
    }

    public class OpenWeatherMain
    {
        [JsonPropertyName("temp")]
        public double Temperature { get; set; }

        [JsonPropertyName("humidity")]
        public int Humidity { get; set; }
    }
}