#include "Task.h"

double a = 2;
double b = 8;
double r = 4;
double M = 234000;

double absolute(){
	return FUNC(b) - FUNC(a);
}

double simps(int n){
	double h = (b - a) / n, res_simps = 0, dx, dx2;
	for (int i = 0; i < n; i++) {
		dx = a + h * i;
		dx2 = a + h * (i + 1);
		res_simps += (dx2 - dx) / 6.0 * (F(dx) + 4.0 * F(0.5 * (dx + dx2)) + F(dx2));
	}
	return res_simps;
}

double task(double e){
	double h = pow(180 * e / ((b - a) * M), 0.25);
	int n = (b - a) / h;
	double er = abs(simps(n) - absolute());
	printf(" 1 - %10.5e %10.5e %10.5e\n", e, h, er);
	return er;
}

void runge(double e){
	double er = task(e);
	double I1n, I2n, Rn;
	int n = 1 / sqrt(er);
	do {
		I1n = simps(n);
		n *= 2;
		I2n = simps(n);
		Rn = 1 / (pow(2, r) - 1) * abs(I1n - I2n);
	} while (Rn > er);
	printf(" 2 - %10.5e %10.5e %10.5e\n\n",er, (b - a) / n, abs(absolute() - I2n));
}
