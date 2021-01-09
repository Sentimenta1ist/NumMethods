#include "Base.h"

double fun(double x) {
	return 15 / sqrt(1 + cos(x)) + 1.5 * x;
}

double der_fun(double x) {
	return (15 * sin(x)) / (2 * pow(1 + cos(x), 1.5)) + 1.5;
}

double der_2_fun(double x) {
	return 15 * (cos(x) / (2 * pow(1 + cos(x), 1.5)) + 3 * sin(x) * sin(x) / (4 * pow(1 + cos(x), 2.5)));
}

void table_chord() {
	printf("  Table Chord Method:\n\n");
	printf("|     EPS    |       RES        |    ERROR   |\n");
	printf("----------------------------------------------\n");
	double eps = 0.01;
	for (int i = 0; i < 4; i++) {
		int num; double err;
		double res = chord(eps, -17, -16, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		res = chord(eps, -15, -14, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		res = chord(eps, -11, -10, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		printf("|            |                  |            |\n");
		eps *= 0.001;
	}
	printf("----------------------------------------------\n");
}

void table_iter() {
	printf("  Table Iter Method:\n\n");
	printf("|     EPS    |       RES        |    ERROR   |\n");
	printf("----------------------------------------------\n");
	double eps = 0.01;
	for (int i = 0; i < 4; i++) {
		int num; double err;
		double res = iter(eps, -17, -16, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		res = iter(eps, -15, -14, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		res = iter(eps, -11, -10, num, err);
		printf("|%e|%17.14lf|%e|\n", eps, res, err);
		printf("|            |                  |            |\n");
		eps *= 0.001;
	}
	printf("----------------------------------------------\n");
}

void table_comparison() {
	printf("  Table Comparison:\n\n");
	printf("|     EPS    |    Chord Method    |  Iterative Method  |\n");
	printf("--------------------------------------------------------\n");
	double eps = 0.01;
	for (int i = 0; i < 4; i++) {
		int num1, num2; double err;
		double res2 = chord(eps, -17, -16, num2, err);
		double res1 = iter(eps, -17, -16, num1, err);
		printf("|%e|%20d|%20d|\n", eps, num2, num1);
		eps *= 0.001;
	}
	printf("--------------------------------------------------------\n");
}