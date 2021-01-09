#include "Task.h"

int main() {
	int n, n2;
	double Uk, eps = 1e-2, a = -10.33, b = 27.4, x = (a + b) / 2, h = (b - a) / 10;


	cout << "                   VARIANT 21 - sin(x)               \n\n";
	cout << "|*****************************************************|\n";
	cout << "|    EPS    |   N   |    ABS ERROR   |       Rn       |\n";
	cout << "|***********|*******|****************|****************|\n";
	while (eps >= 1e-14) {
		double task_res = Task(n, Uk, x, eps, -1);
		cout << "|" << setw(11) << eps;
		cout << "|" << setw(7) << n;
		cout << "|" << setw(16) << abs (abs(sin(x)) - (abs(task_res)));
		cout << "|" << setw(16) << abs(Uk) << "|\n";
		if (eps == 1e-8) n2 = n;
		eps*= 0.001;
	}
	cout << "*******************************************************\n\n";


	cout << "|*********************************************|\n";
	cout << "|     Xi    |    ABS ERROR   |       Rn       |\n";
	cout << "|***********|****************|****************|\n";
	for(int i = 0; i <= 10; i++){
		x = a + h * i;
		double task_res = Task(n, Uk, x, 1e-8, n2);
		cout << "|" << setw(11) << x;
		cout << "|" << setw(16) << abs(abs(sin(x)) - (abs(task_res)));
		cout << "|" << setw(16) << abs(Uk) << "|\n";
	}
	cout << "***********************************************\n";


	return 0;
}