#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct results {
	double error;
	double result;
	int amount;
};

double my_func(double);

double my_der_func(double);

double my_der2_func(double);

results my_iterative_method(double, double, double);

results my_newton_method(double, double, double);