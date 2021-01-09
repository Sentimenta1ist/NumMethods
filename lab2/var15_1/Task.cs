using System;
using System.Collections.Generic;
using System.Text;

namespace AMO_LAB2_ROMANKEVICH
{
	public class Point
	{
		public double A { get; set; }
		public double B { get; set; }
	}

	public class Result
	{
		public double Xn { get; set; }
		public double Error { get; set; }
		public int Count { get; set; }
	}
	class Task
	{
		public double Function(double x)
		{
			return 15 / x - Math.Pow(x, 2) + 15;
		}
		public double Derative1(double x)
		{
			return -15 / Math.Pow(x, 2) - 2*x;
		}

		public List<Point> Intervals(double x1, double x2)
		{
			List<Point> result = new List<Point>();
			for (double i = x1; i < x2; i += 0.5)
			{
				if ((i == 0) || (i == -0.5)) continue;

				if (Function(i) * Function(i + 0.5) < 0)
				{
					if (Derative1(i) * Derative1(i + 0.5) > 0)
					{
						result.Add(new Point() { A = i, B = i + 0.5 });
					}
				}
			}
			return result;
		}
		public List<Result> BisectionMethod(double eps, List<Point> intervals)
		{
			List<Result> result = new List<Result>();
			foreach (var interval in intervals) {
				double an = interval.A, bn = interval.B, xn = 0;
				int count = 0;
				while ((bn - an) > 2 * eps)
				{
					xn = (an + bn) / 2;
					if (Function(an) * Function(xn) < 0) bn = xn;
					else an = xn;
					count++;
				}				
				result.Add(new Result()
				{
					Xn = xn,
					Count = count,
					Error = (bn - an) / 2
				});
			}
			return result;
		}
		public List<Result> IntervalMethod(double eps, List<Point> intervals)
		{
			List<Result> result = new List<Result>();

			foreach (var interval in intervals)
			{
				double a = interval.A, b = interval.B;
				double x0 = (a + b) / 2;
				double M1, m1, xn, lambda, q;
				if (Math.Abs(Derative1(a)) < (Math.Abs(Derative1(b))))
				{
					m1 = Derative1(a);
					M1 = Derative1(b);
				}
				else
				{
					m1 = Derative1(b);
					M1 = Derative1(a);
				}
				lambda = 1 / M1;
				q = 1 - m1 / M1;
				xn = x0;
				int count = 0;
				do
				{
					x0 = xn;
					xn = x0 - lambda * Function(x0);
					count++;
				} while (Math.Abs(xn - x0) > (1 - q) / q * eps);

				result.Add(new Result()
				{
					Xn = xn,
					Count = count,
					Error = Math.Abs(q * Math.Abs(xn - x0) / (1 - q))
				});
			}
			return result;
		}
	}
}
