using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using System;
using System.Threading.Tasks;
using WeatherForecastApp.Models;
using WeatherForecastApp.Services;

namespace WeatherForecastApp.ViewModels
{
    public partial class MainViewModel : ObservableObject
    {
        private readonly CacheService cacheService = new CacheService();

        private readonly LocationService locationService = new LocationService();

        private readonly WeatherService weatherService = new WeatherService();

        [ObservableProperty]
        private string city = "正在加载...";

        [ObservableProperty]
        private string country = "";

        [ObservableProperty]
        private string temperatureKelvin = "-- K";

        [ObservableProperty]
        private string weatherDescription = "暂无天气数据";

        [ObservableProperty]
        private string humidity = "--%";

        [ObservableProperty]
        private string lastUpdated = "尚未更新";

        [ObservableProperty]
        private string statusMessage = "程序已启动";

        [ObservableProperty]
        private bool isLoading;

        public MainViewModel()
        {
            LoadCache();

            _ = InitializeAsync();
        }

        private async Task InitializeAsync()
        {
            await RefreshWeatherAsync();
        }

        private void LoadCache()
        {
            WeatherCacheModel? cache = cacheService.Load();

            if (cache == null)
            {
                City = "暂无缓存";
                Country = "";
                TemperatureKelvin = "-- K";
                WeatherDescription = "尚未获取天气数据";
                Humidity = "--%";
                LastUpdated = "尚未更新";
                StatusMessage = "未找到本地缓存，正在尝试联网获取天气";
                return;
            }

            City = cache.City;
            Country = cache.Country;
            TemperatureKelvin = $"{cache.TemperatureKelvin:F2} K";
            WeatherDescription = cache.WeatherDescription;
            Humidity = $"{cache.Humidity}%";
            LastUpdated = $"缓存时间：{cache.LastUpdated:yyyy-MM-dd HH:mm:ss}";
            StatusMessage = "已从本地 XML 缓存加载天气数据，正在异步更新实时天气";
        }

        private void ShowWeather(WeatherDisplayModel weather)
        {
            City = weather.City;
            Country = weather.Country;
            TemperatureKelvin = $"{weather.TemperatureKelvin:F2} K";
            WeatherDescription = weather.WeatherDescription;
            Humidity = $"{weather.Humidity}%";

            if (weather.IsFromCache)
            {
                LastUpdated = $"缓存时间：{weather.LastUpdated:yyyy-MM-dd HH:mm:ss}";
            }
            else
            {
                LastUpdated = $"更新时间：{weather.LastUpdated:yyyy-MM-dd HH:mm:ss}";
            }
        }

        private void SaveWeatherToCache(WeatherDisplayModel weather)
        {
            WeatherCacheModel cache = new WeatherCacheModel
            {
                City = weather.City,
                Country = weather.Country,
                TemperatureKelvin = weather.TemperatureKelvin,
                WeatherDescription = weather.WeatherDescription,
                Humidity = weather.Humidity,
                Latitude = weather.Latitude,
                Longitude = weather.Longitude,
                LastUpdated = weather.LastUpdated
            };

            cacheService.Save(cache);
        }

        [RelayCommand]
        private async Task RefreshWeatherAsync()
        {
            if (IsLoading)
            {
                return;
            }

            try
            {
                IsLoading = true;
                StatusMessage = "正在根据 IP 自动定位...";

                LocationModel? location = await locationService.GetCurrentLocationAsync();

                if (location == null)
                {
                    StatusMessage = "自动定位失败，已保留本地缓存数据";
                    return;
                }

                City = location.City;
                Country = $"{location.Country} / {location.CountryCode}";
                WeatherDescription = "定位成功，正在获取实时天气...";
                StatusMessage = $"定位成功：{location.City}，正在请求天气数据";

                WeatherDisplayModel? weather = await weatherService.GetCurrentWeatherAsync(location);

                if (weather == null)
                {
                    StatusMessage = "实时天气获取失败，可能是网络异常、API Key 无效或接口限流";
                    return;
                }

                ShowWeather(weather);
                SaveWeatherToCache(weather);

                StatusMessage = "实时天气更新成功，并已写入本地 XML 缓存";
            }
            catch
            {
                StatusMessage = "刷新天气时发生异常，但程序已安全处理";
            }
            finally
            {
                IsLoading = false;
            }
        }

        [RelayCommand]
        private void CreateTestCache()
        {
            WeatherCacheModel model = new WeatherCacheModel
            {
                City = "Shanghai",
                Country = "CN",
                TemperatureKelvin = 299.15,
                WeatherDescription = "Clouds",
                Humidity = 68,
                Latitude = 31.2304,
                Longitude = 121.4737,
                LastUpdated = DateTime.Now
            };

            cacheService.Save(model);

            LoadCache();
        }
    }
}