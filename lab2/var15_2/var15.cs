using System;
using System.Threading;

namespace lab2
{
    internal class LabMath
    {
        public LabMath(Func<double, double> func, Func<double, double> funcDer)
        {
            _func = func;
            _funcDer = funcDer;
        }

        private Func<double, double> _func;
        private Func<double, double> _funcDer;

        public Tuple<double, double> RangeSolution(double a, double b, double step)
        {
            for (var x = a; x <= b; x += step) {
                if (_func(x) * _func(x + step) < 0 &&
                    _funcDer(x) * _funcDer(x + step) > 0) {
                    return new Tuple<double, double>(x, x + step);
                }
            }
            throw new ArgumentException();
        }

        public void BisectionMethod(double a, double b, double eps,
                                     out double x, out double error, out int count)
        {
            var an = a;
            var bn = b;
            x = 0;
            count = 0;
            while (bn - an > 2 * eps)
            {
                x = (an + bn) / 2;
                if (_func(an) * _func(x) < 0) bn = x;
                else an = x;
                count++;
            }
            error = (bn - an) / 2;
        }

        public void IterationMethod(double a, double b, double eps,
                                    out double x, out double error, out int count)
        {
            var x_0 = (a + b) / 2;
            var m1 = _funcDer(a);
            var M1 = _funcDer(b);
            count = 0;

            if (Math.Abs(_funcDer(a)) > Math.Abs(_funcDer(b)))
            {
                m1 = _funcDer(b);
                M1 = _funcDer(a);
            }

            var lambda = 1 / M1;
            var q = 1 - m1 / M1;
            var x_n = x_0;

            do
            {
                x_0 = x_n;
                x_n = x_0 - lambda * _func(x_0);
                count++;
            }
            while (Math.Abs(x_n - x_0) > (1 - q) / q * eps);
            x = x_n;
            error = q * Math.Abs(x_n - x_0) / (1 - q);
        }
    }

    internal static class Program
    {
        private static double Function(double x)
        {
            return 15 / x - Math.Pow(x, 2) + 15;
        }

        private static double FunctionDer(double x)
        {
            return -15 / Math.Pow(x, 2) - 2 * x;
        }

        public static void Main(string[] args)
        {
            var math = new LabMath(Function, FunctionDer);
            Console.WriteLine("    Successive Approximations Method");
            Console.WriteLine("  Eps |              X |          Error |");
            for (var eps = 0.01; eps > 1e-12; eps *= 0.001) {
                double error, x;
                int count;
                var dot = math.RangeSolution(-4, -2, 0.5);
                math.IterationMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
                dot = math.RangeSolution(-2, -0, 0.5);
                math.IterationMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
                dot = math.RangeSolution(3, 5, 0.5);
                math.IterationMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
            }

            Console.WriteLine("\n\n    Bisection Method ");
            Console.WriteLine("  Eps |              X |          Error |");
            for (var eps = 0.01; eps > 1e-12; eps *= 0.001) {
                double error, x;
                int count;
                var dot = math.RangeSolution(-4, -2, 0.5);
                math.BisectionMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
                dot = math.RangeSolution(-2, -0, 0.5);
                math.BisectionMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
                dot = math.RangeSolution(3, 5, 0.5);
                math.BisectionMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,5:G9} | {1,14:G8} | {2,14:G8} |", eps, x, error);
            }

            Console.WriteLine("\n\n    Test ");
            Console.WriteLine("  Eps |  Iteration | Bisection |");
            for (var eps = 0.01; eps > 1e-12; eps *= 0.001) {
                double error, x;
                int count;
                var dot = math.RangeSolution(-4, -2, 0.5);
                math.IterationMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.Write("{0,5:G9} | {1,10} |" , eps, count);

                math.BisectionMethod(dot.Item1, dot.Item2, eps, out x, out error, out count);
                Console.WriteLine("{0,10} |", count);
            }
        }
    }
}