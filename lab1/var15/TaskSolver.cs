using System;
using System.Collections.Generic;
using System.Text;

namespace Lab1_AMO_Variant15
{
    public class TaskSolver
    {
        public double SimplificationX(double oldX)
        {
            if (oldX == 0) return 0;
            int number = 0;
            double newX = Math.Abs(oldX);
            while (newX >= Math.PI)
            {
                newX -= Math.PI;
                number++;
            }
            newX *= oldX / Math.Abs(oldX);
            return (number % 2 == 0) ? newX : -newX;
        }
        public List<double> Task1(double epsilon, double oldX)
        {
            double newX = SimplificationX(oldX);
            List<double> result = new List<double>();
            double Uk = newX;
            double sum = 0;
            int k = 0;
            while (Math.Abs(Uk) >= epsilon)
            {
                sum += Uk;
                k++;
                Uk = -(newX * newX / (4 * k * k + 2 * k)) * Uk;
            }
            double error = (Math.Abs(Math.Abs(Math.Sin(newX)) - Math.Abs(sum)));
            result.Add(error);
            result.Add(Uk);
            result.Add(k);
            return result;
        }
        public List<double> Task2(int n, double oldX)
        {
            List<double> result = new List<double>();
            double newX = SimplificationX(oldX);
            double Uk = newX;
            double sum = 0;
            for (var i = 1; i <= n; i++)
            {
                sum += Uk;
                Uk = -(newX * newX / (4 * i * i + 2 * i)) * Uk;
            }
            double error = (Math.Abs(Math.Abs(Math.Sin(newX)) - Math.Abs(sum)));
            result.Add(error);
            result.Add(Uk);
            return result;
        }
    }
}