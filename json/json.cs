using System;
using System.IO;
using System.Text.Json;

class Program
{
    static int Main(string[] args)
    {
        const string directory = "jsonexamples";

        try
        {
            string[] files = Directory.GetFiles(directory, "*.json");

            foreach (string filePath in files)
            {
                try
                {
                    string jsonContent = File.ReadAllText(filePath);
                    using JsonDocument document = JsonDocument.Parse(jsonContent);
                }
                catch (IOException ex)
                {
                    Console.Error.WriteLine($"json: can't read {filePath}: {ex.Message}");
                    continue;
                }
                catch (JsonException ex)
                {
                    Console.Error.WriteLine($"json: can't parse {filePath}: {ex.Message}");
                    continue;
                }
            }
        }
        catch (DirectoryNotFoundException)
        {
            Console.Error.WriteLine($"json: can't open {directory}");
            return 1;
        }
        catch (UnauthorizedAccessException)
        {
            Console.Error.WriteLine($"json: can't access {directory}");
            return 1;
        }

        return 0;
    }
}
