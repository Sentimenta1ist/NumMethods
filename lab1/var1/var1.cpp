//variant 1
#define _USE_MATH_DEFINES 
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int get_m(double x) {
	int m = 0;
	for (double i = 1; i <= x; i *= 2) {
		m++;
	}
	return m;
}

double my_pow(double base, int pow) {
	double res = 1;
	for (int i = 1; i <= pow; i++) res *= base;
	return res;
}

void ln_x_1(double eps, double x, int& k, double& error, double& Rn, int& n) {
	int m = get_m(x);
	double z = x / my_pow(2, m);
	double a = (1 - z) / (1 + z);
	double sum_Lk = 0;
	double Lk = 1;
	k = 0;
	while (Lk >= 4*eps) {
		k++;
		Lk = my_pow(a, 2 * k - 1) / (2 * (double)k - 1);
		sum_Lk += Lk;
	}
	if (eps == 1e-8) n = k;
	error = abs((m * M_LN2 - 2 * (sum_Lk)) - log(x));
	Rn = abs(Lk);
}

void ln_x_2(int n, double x, double& error, double& Rn) {
	int m = get_m(x);
	double z = x / my_pow(2, m);
	double a = (1 - z) / (1 + z);
	double sum_Lk = 0;
	double Lk = 1;
	for (int k = 1; k <= n; k++) {
		Lk = my_pow(a, 2 * k - 1) / (2 * (double)k - 1);
		sum_Lk += Lk;
	}
	error = abs((m * M_LN2 - 2 * (sum_Lk)) - log(x));
	Rn = abs(Lk);
}

int main(){
	double a = 0.98;
	double b = 5.5;
	double x = (a + b) / 2;
	int n, k;
	cout << " ----------------------------------------" << endl;
	cout << "|Abramov  - Variant 1, ln(x), [0.98; 5.5]|"<< endl;
	cout << " ----------------------------------------" << endl << endl;
	cout << " ----------------------------------------" << endl;
	cout << "|   Eps    |  n  | Abs Error | Remainder |" << endl;
	cout << " ----------------------------------------" << endl;
	for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
		double error, Rn;
		ln_x_1(eps, x, k, error, Rn, n);
		cout << '|' << setw(10) << eps << '|' << setw(5) << k << '|' << setw(10) << error << '|' << setw(10) << Rn << '|' << endl;
		cout << " ----------------------------------------" << endl;
	}
	cout << endl << endl;
	double h = (b - a) / 10;
	cout << " --------------------------------------" << endl;
	cout << "|     Xi     |  Abs Error |  Remainder |" << endl;
	cout << " --------------------------------------" << endl;
	for (int i = 0; i <= 10; i++) {
		double error, Rn;
		ln_x_2(n, a + h * i, error, Rn);
		cout << '|' << setw(12) << a + h * i << '|' << setw(12) << error << '|' << setw(12) << Rn << '|' << endl;
		cout << " --------------------------------------" << endl;
	}
	return 0;
}
