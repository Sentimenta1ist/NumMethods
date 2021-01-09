#include "Meth.h"

SlarCalc::SlarCalc()
{
	x1 = 0;
	x2 = 0;
	x3 = 0;
	x4 = 0;
}

vector<double> Divis(double m, vector<double> b) {
	for (int i = 0; i < size(b); i++)
		b[i] = b[i] / m;
	return b;
}

void SlarCalc::JordanGaussMeth()
{
	vector<vector<double>> b = a;
	for (int j = 0; j < size(b); j++) {
		for (int i = 0; i < size(b); i++) {
			double m = b[i][j];
			if (j != i)
				for (int k = 0; k < size(b[j]); k++) 
					b[i][k] -= m * b[j][k] / b[j][j];
		}
	    b[j] = Divis(b[j][j], b[j]);
	}
	x1 = b[0][4]; x2 = b[1][4]; x3 = b[2][4]; x4 = b[3][4];
}

void SlarCalc::DirectIterMeth(double epsil)
{
	vector<vector<double>> b = {
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}};
	for (int i = 0; i < size(a); i++) {
		for (int j = 0; j < size(a); j++) {
			if (j != i)
				b[i][j] = a[i][j] / a[i][i];
			else
				b[i][j] = a[i][4] / a[i][i];
		}
	}
	double q_pr = 0;
	double q = 0;
	for (int i = 0; i < size(b); i++) {
		for (int j = 0; j < size(b[i]); j++)
			if (j != i)
				q_pr += abs(b[i][j]);
		if (q_pr > q) {
			q = q_pr;
			q_pr = 0;
		}
	}
	double pr_x1 = 0;
	do {
		pr_x1 = x1;
		x1 = b[0][0] - b[0][1] * x2 - b[0][2] * x3 - b[0][3] * x4;
		x2 = b[1][1] - b[1][0] * x1 - b[1][2] * x3 - b[1][3] * x4;
		x3 = b[2][2] - b[2][0] * x1 - b[2][1] * x2 - b[2][3] * x4;
		x4 = b[3][3] - b[3][0] * x1 - b[3][1] * x2 - b[3][2] * x3;
	} while (abs(x1 - pr_x1) > (1 - q) / q * epsil);
}

void SlarCalc::PrintRes()
{
	printf("RESULTS - x1:%13.9lf\tx2:%13.9lf\tx3:%13.9lf\tx4:%13.9lf\n", x1, x2, x3, x4);
}

void SlarCalc::PrintMatr()
{
	for (auto row : a) {
		for (auto el : row)
			printf("%10.5lf ", el);
	    printf("\n");
	}
}

SlarCalc::~SlarCalc()
{

}
