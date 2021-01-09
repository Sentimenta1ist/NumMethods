#include <iostream>
#include <locale.h>

using namespace std;

double max_der2 = 8833;

double func(double x);
double Func(double x);
double abs_value(double a, double b);
double trapezium_method(double a, double b, double eps);
void table1(double a, double b, double eps);
void table2(double a, double b, double eps);



int main(){
    double a = 2, b = 3;
    setlocale(LC_ALL, "Russian");
    printf("    Input error        Step        Gotten error\n");
    table1(a, b, 1e-2);
    table1(a, b, 1e-3);
    table1(a, b, 1e-4);
    table1(a, b, 1e-5);
    printf("   --------------------------------------------\n");
    table2(a, b, 1e-2);
    table2(a, b, 1e-3);
    table2(a, b, 1e-4);
    table2(a, b, 1e-5);
}

double func(double x) {
    return x * x * x * x * (x / 4 + 3.2 - 1.7);
}

double Func(double x) {
    return x * x * x * x * (x * x / 24 + x * 0.3);
}

double abs_value(double a, double b) {
    return Func(b) - Func(a);
}

double trapezium_method(double a, double b, double eps) {
    double h = sqrt((12 * eps) / ((b - a) * max_der2));
    int n = (b - a) / h - 1;
    h = (b - a) / n;
    //cout << n;
    double f0 = func(a) / 2;
    for (int step = 1; step < n; step++) {
        f0 = f0 + func(a + h * step);
    }
    f0 += func(b) / 2;
    return h * f0;
}

double trapezium_method(double a, double b, int n) {
    double h = (b - a) / n;
    double f0 = func(a) / 2;
    for (int step = 1; step < n; step++) {
        f0 = f0 + func(a + h * step);
    }
    f0 += func(b) / 2;
    return h * f0;
}

void table1(double a, double b, double eps) {
    double h = sqrt((12 * eps) / ((b - a) * max_der2));
    int n = (b - a) / h;
    h = (b - a) / n;
    printf("   %e    %e    %e  \n", eps, h, abs(trapezium_method(a, b, eps) - abs_value(a, b)));
}

void table2(double a, double b, double eps){
    double In, In_2, Rn;
    double err = abs(abs_value(a, b) - trapezium_method(a, b, eps));
    int n = 1 / sqrt(err);
    do {
        In = trapezium_method(a, b, n);
        n *= 2;
        In_2 = trapezium_method(a, b, n);
        Rn = (double)1 / 3 * abs(In_2 - In);
    } while (Rn > err);
    printf("   %e    %e    %e  \n", err, (b - a) / n, abs(In_2 - abs_value(a, b)));
}