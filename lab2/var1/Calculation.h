#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Calc {
public:
	Calc();
	double function(double);
	double der_function(double);
	double der_2function(double);
	double get_error_last();
	double get_result_x();
	int get_numbers_of_iter();
	void iterative_meth(double, double, double);
	void raps_meth(double, double, double);
	~Calc(void);
private:
	double error_last;
	double result_x;
	int numbers_of_iter;
};
