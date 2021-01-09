#pragma once
#include <cmath>
#include <iostream>


double fun(double);
double der_fun(double);
double der_2_fun(double);


double chord(double, double, double, int&, double&);
void table_chord();


double iter(double, double, double, int&, double&);
void table_iter();


void table_comparison();
