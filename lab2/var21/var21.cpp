#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

double MyFn(double x) {
    return 3 / (2 + cos(x)) - x / 4;
}

double MyFn_der(double x) {
    return 3 * sin(x) / pow((2 + cos(x)), 2) - 1 / 4;
}

double MyFn_m(double x) {
    return - 3 / (2 + cos(x)) + x / 4;
}

double MyFn_der_m(double x) {
    return - 3 * sin(x) / pow((2 + cos(x)), 2) + 1 / 4;
}

int IterMethod(double a, double b, double e, std::vector<double>& temp, double (*func)(double), double (*dfunc)(double)) {
    /*if (MyFn_der((a + b) / 2) < 0) {
        func = MyFn_m;
        func = MyFn_der_m;
    }*/

    double m1 = dfunc(a);
    double M1 = dfunc(b);
    if (abs(dfunc(a)) > (abs(dfunc(b)))) {
        m1 = dfunc(b);
        M1 = dfunc(a);
    }
    double x = (a + b) / 2, xn = x,
        lambda = 1 / M1, q = 1 - m1 / M1;

    int nums_of_iteration = 0;
    do {
        x = xn;
        xn = x - lambda * func(x);
        nums_of_iteration++;
    } while (abs(xn - x) > ((1 - q) / q) * e);
    temp[0] = xn; //result 
    temp[1] = q * abs(xn - x) / (1 - q);//error
    return nums_of_iteration; //number of iter
}

void TablIter(double a, double b) {
    std::vector<double> some = { 0, 1 };
    for (double e = 0.01; e >= 1e-11; e *= 0.001) {
        int nums_of_iteration = IterMethod(a, b, e, some, MyFn, MyFn_der);
        std::cout << std::setw(10) << e << std::setw(20) << some[0] << std::setw(20) << some[1] << std::endl;
    }
}


int BisMethod(double a, double b, double e, std::vector<double>& temp) {
    int nums_of_iteration = 0;
    while ((b - a) >= 2 * e) {
        temp[0] = (a + b) / 2; //result 
        if (MyFn(a) * MyFn(temp[0]) > 0) {
            a = temp[0];
        }
        else {
            b = temp[0];
        }
        nums_of_iteration++;
    }
    temp[1] = (b - a) / 2;//error
    return nums_of_iteration;
}

void TablBis(double a, double b) {
    std::vector<double> some = { 0, 1 };
    for (double e = 0.01; e >= 1e-11; e *= 0.001) {
        int nums_of_iteration = BisMethod(a, b, e, some);
        std::cout << std::setw(10) << e << std::setw(20) << some[0] << std::setw(20) << some[1] << std::endl;
    }
}

void TablAll() {
    std::vector<double> some = { 0, 1 };
    for (double e = 0.01; e >= 1e-11; e *= 0.001) {
        std::cout << std::setw(10) << e << std::setw(20) << BisMethod(5, 6, e, some) << std::setw(20) << IterMethod(5, 6, e, some, MyFn, MyFn_der) << std::endl;
    }
}

int main(){
    std::cout << "\n                    IterMethod()         Error value\n";
    TablIter(5, 6);
    TablIter(8, 9);
    TablIter(10, 11);
    std::cout << "\n                     BisMethod()         Error value\n";
    TablBis(5, 6);
    TablBis(8, 9);
    TablBis(10, 11);
    std::cout << "\n                            All\n";
    std::cout << "                         BisMethod()         IterMethod()\n";
    TablAll();
}
