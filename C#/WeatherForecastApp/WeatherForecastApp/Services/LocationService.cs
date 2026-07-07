using System;
using System.Net.Http;
using System.Text.Json;
using System.Threading.Tasks;
using WeatherForecastApp.Models;

namespace WeatherForecastApp.Services
{
    public class LocationService
    {
        private static readonly HttpClient httpClient = new HttpClient
        {
            Timeout = TimeSpan.FromSeconds(8)
        };

        public async Task<LocationModel?> GetCurrentLocationAsync()
        {
            try
            {
                string url = "http://ip-api.com/json/?fields=status,message,country,countryCode,city,lat,lon,query&lang=zh-CN";

                using HttpResponseMessage response = await httpClient.GetAsync(url);

                if (!response.IsSuccessStatusCode)
                {
                    return null;
                }

                string json = await response.Content.ReadAsStringAsync();

                IpApiResponse? result = JsonSerializer.Deserialize<IpApiResponse>(json);

                if (result == null || result.Status != "success")
                {
                    return null;
                }

                if (string.IsNullOrWhiteSpace(result.City))
                {
                    return null;
                }

                return new LocationModel
                {
                    City = result.City,
                    Country = result.Country,
                    CountryCode = result.CountryCode,
                    Latitude = result.Latitude,
                    Longitude = result.Longitude,
                    IpAddress = result.IpAddress
                };
            }
            catch
            {
                return null;
            }
        }
    }
}