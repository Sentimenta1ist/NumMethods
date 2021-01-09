#include <iostream>
#include <iomanip>

double M4 = abs(0.0625 * exp(15)* (cos(15) + sin(15)));
double b = 15;
double a = -1;
double r = 4;

double Integrand(double x) {
    return -exp(x) * (sin(x) + cos(x)) / 64;
}

double Antider(double x) {
    return -exp(x) * sin(x) / 64;
}

double DefineInt() {
    return Antider(b) - Antider(a);
}

double simpsonIntegral(int n) {
    const double width = (b - a) / n;
    double simpson_integral = 0;
    for (int step = 0; step < n; step++) {
        double x1 = a + step * width;
        double x2 = a + (step + 1) * width;
        simpson_integral += (x2 - x1) / 6.0 * (Integrand(x1) + 4.0 * Integrand(0.5 * (x1 + x2)) + Integrand(x2));
    }
    return simpson_integral;
}

void tables(double eps) {
    double h = pow(180 * eps / ((b - a) * M4), 0.25);
    int n = (b - a) / h;
    double error_analytical = abs(simpsonIntegral(n) - DefineInt());
    std::cout << " Analytical: "<< std::setw(12) << eps << " " << std::setw(12) 
              << (b - a) / n << " " << std::setw(12) << error_analytical << std::endl;
    double In, I2n, Rn;
    int n1 = 1 / sqrt(error_analytical);
    do {
        In = simpsonIntegral(n1);
        n1 *= 2;
        I2n = simpsonIntegral(n1);
    } while ((1 / (pow(2, r) - 1) * abs(In - I2n)) > error_analytical);
    std::cout << "      Runge: " << std::setw(12) << error_analytical << " " << std::setw(12)
        << (b - a) / n1 << " " << std::setw(12) << abs(I2n - DefineInt()) << std::endl << std::endl;
}

int main(){
    std::cout << "      Method        Input        Width        Error\n";
    for(double eps = 1e-3; eps >= 1e-9; eps*=1e-2)    tables(eps);
}
