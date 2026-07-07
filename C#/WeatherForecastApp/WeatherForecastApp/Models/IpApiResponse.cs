using System.Text.Json.Serialization;

namespace WeatherForecastApp.Models
{
    public class IpApiResponse
    {
        [JsonPropertyName("status")]
        public string Status { get; set; } = "";

        [JsonPropertyName("message")]
        public string Message { get; set; } = "";

        [JsonPropertyName("country")]
        public string Country { get; set; } = "";

        [JsonPropertyName("countryCode")]
        public string CountryCode { get; set; } = "";

        [JsonPropertyName("city")]
        public string City { get; set; } = "";

        [JsonPropertyName("lat")]
        public double Latitude { get; set; }

        [JsonPropertyName("lon")]
        public double Longitude { get; set; }

        [JsonPropertyName("query")]
        public string IpAddress { get; set; } = "";
    }
}