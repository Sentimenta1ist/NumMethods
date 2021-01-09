using System;
using System.Collections.Generic;
using System.Numerics;

namespace Lab1_AMO_Variant15
{
    class Program
    {
        static void Main(string[] args)
        {
            TaskSolver solver = new TaskSolver();
            double a = 10.33;
            double b = 37.4;
            List<double> result = new List<double>();
            int n = 0;
            List<double> epsilons = new List<double> { 1e-2, 1e-5, 1e-8, 1e-11, 1e-14 };
            Console.WriteLine("{0, 5}\t{1, 2}\t{2, 25}\t{3, 25}", "Eps", "N", "Absolute error", "Remainder term");

            foreach (var epsilon in epsilons)
            {
                if (epsilon == 1e-8)
                {
                    n = (int)solver.Task1(epsilon, (a + b) / 2)[2];
                }
                result = solver.Task1(epsilon, (a + b) / 2);
                Console.WriteLine("{0, 5}\t{1, 2}\t{2, 25}\t{3, 25}", epsilon, (int)result[2], result[0], result[1]);
            }

            Console.WriteLine("\n\n{0, 3}\t\t{1, 20}\t\t{2, 20}", "X", "Absolute error", "Remainder term");
            double h = (b - a) / 10;
            for (int i = 0; i <= 10; i++)
            {
                double x = a + h * i;
                result = solver.Task2(n, x);
                Console.WriteLine("{0:.##}\t\t{1, 20}\t\t{2, 20}", x, result[0], result[1]);
            }
        }
    }
}