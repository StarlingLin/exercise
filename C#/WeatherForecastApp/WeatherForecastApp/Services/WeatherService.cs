using System;
using System.Linq;
using System.Net.Http;
using System.Text.Json;
using System.Threading.Tasks;
using WeatherForecastApp.Models;

namespace WeatherForecastApp.Services
{
    public class WeatherService
    {
        private const string ApiKey = "3eb4bd3a75910b3b89ccc7ac12007830";

        private static readonly HttpClient httpClient = new HttpClient
        {
            Timeout = TimeSpan.FromSeconds(10)
        };

        public async Task<WeatherDisplayModel?> GetCurrentWeatherAsync(LocationModel location)
        {
            try
            {
                string url =
                    $"https://api.openweathermap.org/data/2.5/weather?lat={location.Latitude}&lon={location.Longitude}&appid={ApiKey}";

                using HttpResponseMessage response = await httpClient.GetAsync(url);

                if (!response.IsSuccessStatusCode)
                {
                    return null;
                }

                string json = await response.Content.ReadAsStringAsync();

                OpenWeatherResponse? result = JsonSerializer.Deserialize<OpenWeatherResponse>(json);

                if (result == null)
                {
                    return null;
                }

                if (result.Code != 200)
                {
                    return null;
                }

                string description = "Unknown";

                if (result.Weather != null && result.Weather.Any())
                {
                    OpenWeatherInfo info = result.Weather.First();

                    if (!string.IsNullOrWhiteSpace(info.Description))
                    {
                        description = info.Description;
                    }
                    else if (!string.IsNullOrWhiteSpace(info.Main))
                    {
                        description = info.Main;
                    }
                }

                return new WeatherDisplayModel
                {
                    City = string.IsNullOrWhiteSpace(result.CityName) ? location.City : result.CityName,
                    Country = location.CountryCode,
                    TemperatureKelvin = result.Main.Temperature,
                    WeatherDescription = description,
                    Humidity = result.Main.Humidity,
                    Latitude = location.Latitude,
                    Longitude = location.Longitude,
                    LastUpdated = DateTime.Now,
                    IsFromCache = false
                };
            }
            catch
            {
                return null;
            }
        }
    }
}