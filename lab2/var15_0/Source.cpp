#include "Source.h"

double func(double x) {
	return 15 / x - pow(x, 2) + 15;
}

double der_func(double x) {
	return - 15 / pow(x, 2) - 2 * x;
}

pair<double, double> range_pair(double a, double b, double step) {
	pair < double, double > range;
	for (double x = a; x <= b; x += step) {
		if ((func(x) * func(x + step) < 0) && (der_func(x) * der_func(x + step) > 0)) {
			range.first = x;
			range.second = x + step;
			return range;
		}
	}
}

void bisection(double a, double b, double eps, double& x, double& error, int& count) {
    double an = a;
    double bn = b;
    count = 0;
    while ((bn - an) > 2*eps) {
        x = (an + bn) / 2;
        if (func(an) * func(x) < 0) bn = x;
        else an = x;
        count++;
    }
    error = (bn - an) / 2;
}

void iter(double a, double b, double eps, double& x, double& error, int& count) {
	double x_0 = (a + b) / 2;
    double m1 = der_func(a);
    double M1 = der_func(b);
    double x_n, lambda, q;
    if (fabs(der_func(a)) > (fabs(der_func(b)))) {
        m1 = der_func(b);
        M1 = der_func(a);
    }
    lambda = 1 / M1;
    q = 1 - m1 / M1;
    x_n = x_0;
    count = 0;
    do {
        x_0 = x_n;
        x_n = x_0 - lambda * func(x_0);
        count++;
    } while (fabs(x_n - x_0) > ((1 - q) / q) * eps);
    x = x_n;
    error = q * fabs(x_n - x_0) / (1 - q);
}

void table1() {
    cout << "    Method of Successive Approximations \n\n";
    cout << "         eps|               x|        error\n";
    for (double eps = 0.01; eps > 1e-12; eps *= 0.001) {
        double error, r_n, x;
        int count;
        pair<double, double> dot = range_pair(-4, -2, 0.5); //Roots range by plot
        iter(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n", eps, x, error);
        dot = range_pair(-2, -0, 0.5); 
        iter(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n", eps, x, error);
        dot = range_pair(3, 5, 0.5); 
        iter(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n\n", eps, x, error);
    }
}

void table2() {
    cout << "                Bisection Method         \n\n";
    cout << "         eps|               x|        error\n";
    for (double eps = 0.01; eps > 1e-12; eps *= 0.001) {
        double error, r_n, x;
        int count;
        pair<double, double> dot = range_pair(-4, -2, 0.5); //Roots range by plot
        bisection(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n", eps, x, error);
        dot = range_pair(-2, -0, 0.5); 
        bisection(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n", eps, x, error);
        dot = range_pair(3, 5, 0.5); 
        bisection(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15.10lf| %4e\n\n", eps, x, error);
    }

}

void table3() {
    cout << "\n\n                        Test                 \n\n";
    cout << "         eps|       Iteration|      Bisection\n";
    for (double eps = 0.01; eps > 1e-12; eps *= 0.001) {
        double error, r_n, x;
        int count;
        pair<double, double> dot = range_pair(-4, -2, 0.5); //Roots range by plot
        iter(dot.first, dot.second, eps, x, error, count);
        printf("%4e| %15d|" , eps, count);

        bisection(dot.first, dot.second, eps, x, error, count);
        printf("%15d\n", count);    
    }
}