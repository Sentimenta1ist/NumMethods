#include "Calc.h"

double Rn(double eps, int& n, double x, double& result) {
	double Un = 1;
	result = 0;
	while (abs(Un) >= eps) {
		result += Un;
		Un = x * x / (2 * n * (2 * n - 1)) * Un;
		n++;
	}
	n = n - 1;
	return Un;
}

double Rn(int n, double x, double& result) {
	double Un = 1;
	result = 0;
	for(int  i = 1; i <= n; i++){
		result += Un;
		Un = x * x / (2 * i * (2 * i - 1)) * Un;
	}
	return Un;
}