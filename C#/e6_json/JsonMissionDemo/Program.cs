using System.Text;
using System.Text.Json;

using MemoryStream stream = new MemoryStream();

using Utf8JsonWriter writer = new Utf8JsonWriter(stream, new JsonWriterOptions
{
    Indented = true
});

writer.WriteStartObject();

writer.WriteString("Date", "2019-08-01T00:00:00");
writer.WriteNumber("Temperature", 25);
writer.WriteString("Summary", "Hot");

writer.WriteStartArray("DatesAvailable");
writer.WriteStringValue("2019-08-01T00:00:00");
writer.WriteStringValue("2019-08-02T00:00:00");
writer.WriteEndArray();

writer.WriteEndObject();
writer.Flush();

string result = Encoding.UTF8.GetString(stream.ToArray());

Console.WriteLine(result);