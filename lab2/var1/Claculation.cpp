#include "Calculation.h"

Calc::Calc() 
{
	error_last = 0;
	result_x = 0;
	numbers_of_iter = 0;
}
Calc::~Calc(void) 
{
}

double Calc::function(double x) 
{
	return 5 * pow(x, 3) - 6 * exp(x) + 15;
}

double Calc::der_function(double x) 
{
	return 15 * x * x - 6 * exp(x);
}

double Calc::der_2function(double x) 
{
	return 30 * x - 6 * exp(x);
}

double Calc::get_error_last()
{
	return error_last;
}

double Calc::get_result_x()
{
	return result_x;
}

int Calc::get_numbers_of_iter()
{
	return numbers_of_iter;
}


void Calc::iterative_meth(double epsi, double a, double b) 
{
	double m1 = der_function(a);
	double M1 = der_function(b);

	//if df(x) < 0;
	if (abs(M1) < abs(m1)) 
	{
		double k = M1;
		M1 = m1;
		m1 = k;
	}

	double xprev = (a + b) / 2;
	double lambda = 1 / M1;
	double q = 1 - m1 / M1;

	//calculation
	result_x = xprev;
	numbers_of_iter = 0;
	do 
	{
		xprev = result_x;
		result_x = xprev - lambda * function(xprev);
		numbers_of_iter++;
	} while (abs(result_x - xprev) > (1 - q) / q * epsi);

	error_last = q * abs(result_x - xprev) / (1 - q);
}

void Calc::raps_meth(double epsi, double a, double b)
{
	//check for second deriv
	result_x = a;
	if (function(a) * der_2function(a) < 0)
	{
		result_x = b;
	}
	double m1 = min(abs(der_function(a)), abs(der_function(b)));
	
	//calculation
	numbers_of_iter = 0;
	do {
		result_x -= function(result_x) / der_function(result_x);
		numbers_of_iter++;
	}while (abs(function(result_x)) / m1 > epsi);

	error_last = abs(function(result_x)) / m1;
}
