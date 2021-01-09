#include "Methods.h"

double my_func(double x) {
	return x * x * x + x * x - sin(x) - 0.5;
}

double my_der_func(double x) {
	return 3 * x * x + 2 * x - cos(x);
}

double my_der2_func(double x) {	
	return 6 * x + 2 + sin(x);
}

results my_iterative_method(double eps, double a, double b) {
	double m1 = my_der_func(a);
	double M1 = my_der_func(b);

	if (abs(M1) < abs(m1)) {
		double tmp = m1;
		m1 = M1;
		M1 = tmp;
	}
	results this_res;

	double x0 = (a + b) / 2, lambda = 1 / M1 , q = 1 - m1 / M1;

	this_res.result = x0;
	this_res.amount = 0;

	do {
		x0 = this_res.result;
		this_res.result = x0 - lambda * my_func(x0);
		this_res.amount++;
	} while (abs(this_res.result - x0) > ((1 - q) / q) * eps);

    this_res.error = q * abs(this_res.result - x0) / (1 - q);
	return this_res;
}

results my_newton_method(double eps, double a, double b) {
	results this_res;
	this_res.amount = 1;
	double m1 = min(abs(my_der_func(a)), abs(my_der_func(b))), xn;

	if (my_func(a) * my_der2_func(a) > 0) {
		xn = a;
	}
	else {
		xn = b;
	}
	
	xn -= my_func(xn) / my_der_func(xn);

	while (abs(my_func(xn)) / m1 > eps) {
		xn -= my_func(xn) / my_der_func(xn);
		this_res.amount++;
	}

	this_res.result = xn;
	this_res.error = abs(my_func(xn)) / m1;
	return this_res;
}
