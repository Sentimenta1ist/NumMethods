#include "Calc.h"


int a = 0, b = 10;

int main() {
	double Un = 1, x = (b + a)/2, res = 0;
	int n = 1;
	cout << "First:" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "|eps    |n    |abs error        |remainder       |" << endl;
	cout << "--------------------------------------------------" << endl;
	for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
		double remainder = Rn(eps, n, x, res);
		cout << "|"  << setw(7) << eps << "|";
		cout << setw(5) << n << "|";
		cout << setw(17) << abs(abs(res) - abs(cosh(x)))<< "|";
		cout << setw(16) << remainder << "|" << endl;
		n = 1;
		res = 0;
	}
	cout << "--------------------------------------------------" << endl;
	
	double remainder = Rn(1e-8, n, x, res);
	int new_n = n;
	double h = (double)(b - a) / 10;
	cout << h ;
	cout << "Second:" << endl;
	cout << "------------------------------------------" << endl;
	cout << "|Xi    |abs error        |remainder       |" << endl;
	cout << "------------------------------------------" << endl;
	for (int i = 0; i <= 10; i++) {
		double x = a + h * i;
		double remainder = Rn(new_n, x, res);
		cout << "|" << setw(6) << x << "|";
		cout << setw(17) << abs(abs(res) - abs(cosh(x))) << "|";
		cout << setw(16) << remainder << "|" << endl;
	}
	cout << "------------------------------------------" << endl;

	cout << cosh(-20);
	return 0;
}
