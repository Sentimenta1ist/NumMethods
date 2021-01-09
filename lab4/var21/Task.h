#pragma once
#include <iostream>

#define F(x)(pow(3 * x + 1, 5))
#define FUNC(x)(pow(3 * x + 1, 6) / 18)

using namespace std;

double absolute();
double simps(int);
void runge(double);
double task(double);
