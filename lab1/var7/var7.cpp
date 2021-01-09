// Vargan_AMO_1.cpp :variant 6	chx	[-10.8; 11.9]

#include <iostream>
#include <utility>
#include <cmath>

std::pair <double, double> Error_Rn(double eps, double x, int& k) {
	std::pair <double, double> error_rn;
	double Uk = 1, ch_x = Uk;
	k = 0;
	while (abs(Uk) >= eps) {
		k++;
		Uk = x * x / (2 * k * (2 * k - 1)) * Uk;
		ch_x += Uk;
	}
	error_rn.first = abs(ch_x - cosh(x));
	error_rn.second = Uk;
	return error_rn;
}

std::pair <double, double> Error_Rn(int n, double x) {
	std::pair <double, double> error_rn;
	double Uk = 1, ch_x = Uk;
	for (int k = 1; k <= n; k++) {
		Uk = x * x / (2 * k * (2 * k - 1)) * Uk;
		ch_x += Uk;
	}
	error_rn.first = abs(ch_x - cosh(x));
	error_rn.second = Uk;
	return error_rn;
}

int main(){
	double a = -10.8, b = 11.9, x = (a + b) / 2, h = (b - a) / 10;
	int n;
	printf("\t\t\t                          VARIANT 6                        \n");
	printf("\t\t\t             ch(x)                     [-10.8; 11.9]       \n");
	printf("\t\t\t===============================================================\n\n\n");
	printf("\t\t\t|    Epsilon    |     n     |   Abs_Error    |    Rem_term    |\n");
	printf("\t\t\t|===============|===========|================|================|\n");
	for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
		int k;
		std::pair<double, double> Res = Error_Rn(eps, x, k);
		printf("\t\t\t|%15.0e|%11d|%15.10e|%15.10e|\n", eps, k, Res.first, Res.second);
		if (eps == 1e-8) n = k;
	}
	printf("\t\t\t==============================================================\n\n\n");
	printf("\t\t\t\t|     Xi      |   Abs_Error    |    Rem_term    |\n");
	printf("\t\t\t\t|=============|================|================|\n");
	for (int i = 0; i <= 10; i++) {
		x = a + h * i;
		std::pair<double, double> Res = Error_Rn(n, x);
		printf("\t\t\t\t|%13.3lf|%15.10e|%15.10e|\n",x, Res.first, Res.second);
	}	
	printf("\t\t\t\t=================================================\n\n\n");
}
