#include "Base.h"

double iter(double eps, double a, double b, int& num, double& err) {
    double M1 = der_fun(b), m1 = der_fun(a);
    if (abs(der_fun(a)) > (abs(der_fun(b)))) {
        m1 = der_fun(b);
        M1 = der_fun(a);
    }
    double lambda = 1 / M1, q = 1 - m1 / M1, x0 = (a + b) / 2, xn = x0 - lambda * fun(x0);
    num = 1;
    while (abs(xn - x0) > (1 - q) / q * eps) {
        x0 = xn;
        xn = x0 - lambda * fun(x0);
        num++;
    }
    err = q * abs(xn - x0) / (1 - q);
    return xn;
}