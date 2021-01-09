#pragma once
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int siz = 4;

extern vector<vector<double>> m;

void print_row(vector<double>);

vector<double> JordanGauss();

vector<double> DirectIteration(double);