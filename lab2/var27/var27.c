#include <stdio.h>
#include <math.h>
#include <malloc.h>

double function(double x)
{
   return x * x - pow(cos(3 * x), 2) + sin(4 * x) + 0.9;
}

double function_der1(double x)
{
   return 2 * x + 6 * cos(3 * x) * sin(3 * x) + 4 * cos(4 * x);
}

struct interval {
   double a;
   double b;
   struct interval* next;
};

struct interval* get_roots(double a, double b,
                           double (*func)(double), double (*func_der)(double))
{
   double const step = 0.01;
   struct interval* roots = NULL, *tail = NULL;
   for(double x = a; x < b; x += step)
      if(func(x) * func(x + step) < 0 &&
         func_der(x) * func_der(x + step) > 0)
      {
           struct interval* new_int = malloc(sizeof(struct interval));
           new_int->a = x;
           new_int->b = x + step;
           new_int->next = NULL;
           if(roots) tail->next = new_int;
           else roots = new_int;
           tail = new_int;
      }
   return roots;
}

void free_intervals(struct interval* intervals)
{
   while(intervals)
   {
      struct interval* tmp = intervals;
      intervals = intervals->next;
      free(tmp);
   }
}


int bisection(double a, double b, double epsilon, double* x, double* error,
               double (*func)(double), double (*func_der)(double))
{
   double an = a;
   double bn = b;
   int count = 0;
   while ((bn - an) > 2 * epsilon)
   {
      *x = (an + bn) / 2;
      if (func(an) * func(*x) < 0) bn = *x;
      else an = *x;
      count++;
   }
   *error = (bn - an) / 2;
   return count;
}

int iteration(double a, double b, double epsilon, double* xn, double* error,
               double (*func)(double), double (*func_der)(double))
{
   double x0 = (b + a) / 2;
   double m1 = func_der(a);
   double m2 = func_der(b);
   double lambda, q;
   int count = 0;

   if (fabs(func_der(b)) < fabs(func_der(a)))
   {
      m1 = func_der(b);
      m2 = func_der(a);
   }

   lambda = 1 / m2;
   q = 1 - m1 / m2;
   *xn = lambda * func(x0);
   while (fabs(*xn - x0) > (1 - q) / q * epsilon)
   {
      x0 = *xn;
      *xn -= lambda * func(*xn);
      count++;
   }

   *error = q * fabs(*xn - x0) / (1 - q);
   return count;
}

int main(int argc, char** argv)
{
   struct interval *roots = get_roots(-2, 2, function, function_der1), *iterator;

   printf("Iteration method:\n\n");
   printf("   EPS         X           ERR\n");
   for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001)
   {
      iterator = roots;
      while (iterator)
      {
         double xn, err;
         iteration(iterator->a, iterator->b, epsilon, &xn, &err,
                   function, function_der1);
         printf("%5.4e %10.6f %12.4e\n", epsilon, xn, err);
         iterator = iterator->next;
      }
   }

   printf("\n\nBisection method:\n");
   printf("   EPS         X           ERR\n");
   for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001) {
      iterator = roots;
      while (iterator)
      {
         double xn, err;
         bisection(iterator->a, iterator->b, epsilon, &xn, &err,
                   function, function_der1);
         printf("%5.4e %10.6f %12.4e\n", epsilon, xn, err);
         iterator = iterator->next;
      }
   }

   iterator = roots;
   printf("\n\nBisection method:\n");
   printf("   EPS         ITER           BISEC\n");
   for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001) {
      double xn, err;
      int count_it = iteration(iterator->a, iterator->b, epsilon, &xn, &err,
                     function, function_der1),
          count_bi = bisection(iterator->a, iterator->b, epsilon, &xn, &err,
                     function, function_der1);
      printf("%5.4e %10i %12i\n", epsilon, count_it, count_bi);
   }

   free_intervals(roots);
   return 0;
}
