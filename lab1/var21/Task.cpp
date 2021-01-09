#include "Task.h"

double Reduction(double x) {
	int k = 0;
	if (x == 0) return 0;
	else if (x > 0)
		for (double i = x; i >= M_PI; i -= M_PI) k++;
	else
		for (double i = x; i <= -M_PI; i += M_PI) k--;
	return (k % 2 == 0) ? (x - M_PI * k) : -(x - M_PI * k);
}

double Task(int& n, double& Uk, double x, double eps, int n2) {
	double task_res = 0;
	x = Reduction(x);
	n = 0;
	for (Uk = x; abs(Uk) > eps; Uk *= -(x * x / (2 * n * (2 * n + 1)))) {
		n++;
		task_res += Uk;
	}
	task_res = 0;
	Uk = x;
	if (n2 == -1) n2 = n;
	for (int i = 1; i <= n; i++) {
		task_res += Uk;
		Uk = -(x * x / (2 * i * (2 * i + 1))) * Uk;
	}
	return task_res;
}