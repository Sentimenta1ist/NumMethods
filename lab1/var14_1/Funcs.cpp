#include "Funcs.h"

double simple(double x) {
	if (x == 0) return 0;
	for (double i = abs(x); i >= 2 * PI; i -= 2 * PI) x = abs(x) - 2 * PI;
	return x;
}


void func1(double eps, double x, int& n, double& err, double &rn) {
	double un = 1, sum = 0; n = 0;
	x = simple(x);
	while (abs(un) > eps) {
		sum += un;
		n++;
		un = -(x * x / (2 * (double)n * (2 * (double)n - 1))) * un;
	}
	rn = abs(un);
	err = abs(abs(cos(x)) - abs(sum));
}

void func2(int n, double x, double& err, double& rn) {
	double un = 1, sum = 0;
	x = simple(x);
	for (int i = 1; i <= n; i++) {
		sum += un;
		un = -(x * x / (2 * (double)i * (2 * (double)i - 1))) * un;
	}
	rn = abs(un);
	err = abs(abs(cos(x)) - abs(sum));
}

