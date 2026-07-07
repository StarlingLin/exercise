namespace WeatherForecastApp.Models
{
    public class WeatherCacheModel
    {
        public string City { get; set; } = "";

        public string Country { get; set; } = "";

        public double TemperatureKelvin { get; set; }

        public string WeatherDescription { get; set; } = "";

        public int Humidity { get; set; }

        public double Latitude { get; set; }

        public double Longitude { get; set; }

        public DateTime LastUpdated { get; set; } = DateTime.Now;
    }
}