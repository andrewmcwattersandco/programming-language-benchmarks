using System;

record Record(int Id);

class Program
{
    static void Main(string[] args)
    {
        const int nRecords = 8388608;

        try
        {
            Record[] records = new Record[nRecords];

            for (int i = 0; i < nRecords; i++)
            {
                Record r = new Record(i);
                records[i] = r;
            }
        }
        catch (OutOfMemoryException ex)
        {
            Console.Error.WriteLine($"record: out of memory: {ex.Message}");
            Environment.Exit(1);
        }
    }
}
