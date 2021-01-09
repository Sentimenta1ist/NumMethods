#include "Base.h"

double chord(double eps, double a, double b, int& num, double& err) {
    double c  = a, xn = b, m1 = std::min(abs(der_fun(a)), abs(der_fun(b)));
    if ((fun(a) * der_2_fun(a)) < 0) {
        c = b;
        xn = a;
    }
    xn = xn - (fun(xn) / (fun(xn) - fun(c))) * (xn - c);
    num = 1;
    while (fabs(fun(xn)) / m1 > eps){
        xn = xn - (fun(xn) / (fun(xn) - fun(c))) * (xn - c);
        num++;
    }
    err = fabs(fun(xn) / m1);
    return xn;
}