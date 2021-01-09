#include <iostream>
#include <cmath>
#include <iomanip>

int first_task(double eps, double x, double &absolute_error, double & Rn) {
	/*return number of row elements, change absolute error and remainder term*/
	int k = 0;
	double Uk = x, sum = 0;
	while (abs(Uk) >= eps) {
		k++;
		sum += Uk;
		Uk = ((x * x) / (2 * k * (2 * k + 1))) * Uk;
	}
	absolute_error = abs (abs(sum) - abs(sinh(x)));
	Rn = Uk;
	return k--;
}

double second_task(int n, double x, double& absolute_error) {
	/*return remainder term, change absolute error*/
	double  Uk = x, sum = 0;
	for (int k = 1; k <= n; k++) {
		sum += Uk;
		Uk = ((x * x) / (2 * k * (2 * k + 1))) * Uk;
	}
	absolute_error = abs (abs(sum) - abs(sinh(x)));
	return Uk;
}

int main(){
	double a = -0.8, b = 16.9, x = (a + b) / 2, absolute_error = 0, Rn = 0;
	int n = 0, n_for_second_task = 0;
	std::cout << "---  Variant 11  ---   sh(x)  ---  [-0.8; 16.9]  ---\n\n";
	std::cout << "--------------------- First Task -------------------\n";
	std::cout << "----------------------------------------------------|\n";
	std::cout << "|   eps   |   n   | Absolute error | Remainder term |\n";
	std::cout << "|---------|-------|----------------|----------------|\n";
	for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
		n = first_task(eps, x, absolute_error, Rn);
		if (eps == 1e-8) n_for_second_task = n;
		std::cout << "|" << std::setw(9) << eps << "|" << std::setw(7) << n << "|" << std::setw(16) << absolute_error << "|" << std::setw(16) << abs(Rn) << "|\n";
	}
	std::cout << "-----------------------------------------------------\n\n";

	std::cout << "--------------- Second Task ----------------\n";
	std::cout << "--------------------------------------------\n";
	std::cout << "|   xi   | Absolute error | Remainder term |\n";
	std::cout << "--------------------------------------------\n";
	double h = (b - a) / 10;
	for (int i = 0; i <= 10; i++) {
		double x = a + h * i;
		Rn = second_task(n_for_second_task, x, absolute_error);
		std::cout << "|" << std::setw(8) << x << "|" << std::setw(16) << absolute_error << "|" << std::setw(16) << abs(Rn) << "|\n";
	}
	std::cout << "--------------------------------------------\n";
    return 0;
}
