using System;
using System.Diagnostics;
using System.Linq;
using HPCsharp;
using HPCsharp.Algorithms;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] sizes = { 2000, 20000000 };

            Console.WriteLine("环境自己填,数组长度,普通Sum/ms,HPCsharp Sum/ms,普通Max/ms,HPCsharp Max/ms,普通Sum结果,HPCsharp Sum结果,普通Max结果,HPCsharp Max结果");

            foreach (int size in sizes)
            {
                double[] data = GenerateDoubleArray(size);

                double normalSumResult = 0;
                double hpcSumResult = 0;
                double normalMaxResult = 0;
                double hpcMaxResult = 0;

                Stopwatch stopwatch = new Stopwatch();

                stopwatch.Restart();
                for (int i = 0; i < 20; i++)
                {
                    normalSumResult = data.Sum();
                }
                stopwatch.Stop();
                double normalSumTime = stopwatch.Elapsed.TotalMilliseconds / 20.0;

                stopwatch.Restart();
                for (int i = 0; i < 20; i++)
                {
                    hpcSumResult = data.SumHpc();
                }
                stopwatch.Stop();
                double hpcSumTime = stopwatch.Elapsed.TotalMilliseconds / 20.0;

                stopwatch.Restart();
                for (int i = 0; i < 20; i++)
                {
                    normalMaxResult = data.Max();
                }
                stopwatch.Stop();
                double normalMaxTime = stopwatch.Elapsed.TotalMilliseconds / 20.0;

                stopwatch.Restart();
                for (int i = 0; i < 20; i++)
                {
                    hpcMaxResult = data.MaxHpc();
                }
                stopwatch.Stop();
                double hpcMaxTime = stopwatch.Elapsed.TotalMilliseconds / 20.0;

                Console.WriteLine($"手动填写,{size},{normalSumTime:F6},{hpcSumTime:F6},{normalMaxTime:F6},{hpcMaxTime:F6},{normalSumResult:F10},{hpcSumResult:F10},{normalMaxResult:F10},{hpcMaxResult:F10}");
            }

            Console.ReadKey();
        }

        static double[] GenerateDoubleArray(int length)
        {
            Random random = new Random(2024);
            double[] data = new double[length];

            for (int i = 0; i < data.Length; i++)
            {
                data[i] = random.NextDouble();
            }

            return data;
        }
    }
}