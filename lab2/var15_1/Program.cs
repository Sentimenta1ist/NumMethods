using System;
using System.Collections.Generic;

namespace AMO_LAB2_ROMANKEVICH
{
	
	class Program
	{
		 static void Main(string[] args)
		{
			List<double> epss = new List<double>() { 1e-2, 1e-5, 1e-8, 1e-11, 1e-14 };
			Task task = new Task();
			List<Point> this_intervals = task.Intervals(-5, 5);
			Console.WriteLine("          BISECTION METHOD             ");
			Console.WriteLine("|    eps|                     xn|               err|");
			Console.WriteLine("|-------|-----------------------|------------------|");
			foreach (var eps in epss)
			{
				List<Result> secantResults = task.BisectionMethod(eps, this_intervals);
				foreach (var secantResult in secantResults)
				{
					Console.WriteLine("{0, 5}\t|{1, 18}\t|{2, 18}|", eps, secantResult.Xn, secantResult.Error);
				}
			}
			Console.WriteLine("-------------------------------------------------------");

			Console.WriteLine("            ITERATIVE METHOD           ");
			Console.WriteLine("|    eps|                     xn|                  err|");
			Console.WriteLine("|-------|-----------------------|---------------------|");
			foreach (var eps in epss)
			{
				List<Result> intervalResults = task.IntervalMethod(eps, this_intervals);
				foreach (var intervalResult in intervalResults)
				{
					Console.WriteLine("{0, 5}\t|{1, 18}\t|{2, 22}|", eps, intervalResult.Xn, intervalResult.Error);
				}
			}
			Console.WriteLine("-------------------------------------------------------"); 
			Console.WriteLine("                Comparison             ");
			Console.WriteLine("|  eps|  count by iter| count by bisec|");
			Console.WriteLine("|-----|---------------|---------------|");
			foreach (var eps in epss)
			{
				List<Result> intervalResults = task.IntervalMethod(eps, this_intervals);
				List<Result> secantResults = task.BisectionMethod(eps, this_intervals);
				Console.WriteLine("{0, 5} |{1, 15}| {2, 12}  |", eps, intervalResults[0].Count, secantResults[0].Count);
			}
		}

	}
}
