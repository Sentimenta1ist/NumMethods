#include <iostream>

using namespace std;

double a = 1, b = 17, M = exp(17) - 1, r = 2;

double f(double x) {
    return exp(x) - x * x / 2 - x;
}

double F(double x) {
    return exp(x) - x * x * x / 6 - x * x / 2;
}

double leibniz() {
    return F(b) - F(a);
}

double trapz (double n) {
    double res = f(a) / 2;
    double h = (b - a) / n;
    for (int i = 1; i < n; i++) 
        res += f(a + h * i);
    return h * (res + f(b) / 2);
}

double task1(double eps, int out) {
    double h = sqrt((12 * eps) / ((b - a) * M));
    int n = (b - a) / h;
    if (n % 2 != 0)  n--;
    double res = trapz(n);
    if (out) printf(" | %5.3e | %.10e | %.10e |\n", eps, (b - a) / n, abs(res - leibniz()));
    return res;
}

void task2_runge(double eps) {
    eps = abs(leibniz() - task1(eps, false));
    int n = 1 / pow(eps, 1 / r);
    double In, I2n, Rn;
    do {
        In = trapz(n);
        n *= 2;
        I2n = trapz(n);
        Rn = (double)1 / 3 * abs(In - I2n);
    } while (Rn > eps);
    printf(" | %5.3e | %.10e | %.10e |\n", eps, (b - a) / n, abs(I2n - leibniz()));
}

int main(){
    printf(" Task 1:\n");
    printf(" ---------------------------------------------------\n");
    printf(" |    eps    |       step       |       error      |\n");
    printf(" ------------|------------------|-------------------\n");
    task1(1e-1, true);
    task1(1e-2, true);
    task1(1e-3, true);
    task1(1e-4, true);
    printf(" ---------------------------------------------------\n");

    printf("\n Task 2:\n");
    printf(" ---------------------------------------------------\n");
    printf(" |    eps    |       step       |       error      |\n");
    printf(" ------------|------------------|-------------------\n");
    task2_runge(1e-1);
    task2_runge(1e-2);
    task2_runge(1e-3);
    task2_runge(1e-4);
    printf(" ---------------------------------------------------\n");
}
