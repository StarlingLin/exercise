using System;
using System.IO;
using System.Xml.Serialization;
using WeatherForecastApp.Models;

namespace WeatherForecastApp.Services
{
    public class CacheService
    {
        private readonly string cacheFilePath;

        public CacheService()
        {
            string appDataPath = Path.Combine(
                Environment.GetFolderPath(Environment.SpecialFolder.LocalApplicationData),
                "WeatherForecastApp"
            );

            if (!Directory.Exists(appDataPath))
            {
                Directory.CreateDirectory(appDataPath);
            }

            cacheFilePath = Path.Combine(appDataPath, "weather_cache.xml");
        }

        public WeatherCacheModel? Load()
        {
            try
            {
                if (!File.Exists(cacheFilePath))
                {
                    return null;
                }

                XmlSerializer serializer = new XmlSerializer(typeof(WeatherCacheModel));

                using FileStream stream = new FileStream(cacheFilePath, FileMode.Open);

                return serializer.Deserialize(stream) as WeatherCacheModel;
            }
            catch
            {
                return null;
            }
        }

        public void Save(WeatherCacheModel model)
        {
            try
            {
                XmlSerializer serializer = new XmlSerializer(typeof(WeatherCacheModel));

                using FileStream stream = new FileStream(cacheFilePath, FileMode.Create);

                serializer.Serialize(stream, model);
            }
            catch
            {
            }
        }
    }
}