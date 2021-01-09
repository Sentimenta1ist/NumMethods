//Variant 14, AMO, 1 lab, cos(x), [-31.3; -4.9]
#include "Funcs.h"

int main() {
	double a = -31.3, b = -4.9, err, rn, x = (a + b) / 2, h = (b - a) / 10;
	int n, n2;

	printf("First table (x = %.2lf):\n", x);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|     eps    |  n  |   absolute error   |   remainder term   |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
		func1(eps, x, n, err, rn);
		if (eps == 1e-8) {
			n2 = n;
			printf("|\t%.e|%5d|%20.5e|%20.5e| *check!*\n", eps, n, err, rn);
			continue;
		}
		printf("|\t%.e|%5d|%20.5e|%20.5e|\n", eps, n, err, rn);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");

	printf("Second table (n = %d):\n", n2);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("|      x      |   absolute error   |   remainder term   |\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	for (int i = 0; i <= 10; i++) {
		x = a + h * i;
		func2(n2, x, err, rn);
		if (x == (a + b) / 2) {
			printf("|%13.2lf|%20.5e|%20.5e| *check!*\n", x, err, rn);
			continue;
		}
		printf("|%13.2lf|%20.5e|%20.5e|\n", x, err, rn);
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	std::cout << simple(-31);
	return 0;
}
