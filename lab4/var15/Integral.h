#pragma once
#include <iostream>

using namespace std;

class Integral {
public:
    Integral();
    double Fintegral(double);
    double Fantider(double);
    double Newton();
    double SimpsonMethod(int);
    void Tab1(double);
    void Tab2(double);
    ~Integral();
private:
    double a = 2;
    double b = 10;
    double r = 4;
    double maxder = 22920;
    double z = 180;
    double sqr_pow = 0.25;
    double curr_err = 1;
};
