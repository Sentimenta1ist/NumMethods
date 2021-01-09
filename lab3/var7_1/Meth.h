#pragma once

#include <iostream>
#include <vector>

using namespace std;

class SlarCalc {
	public:
		SlarCalc();
		void JordanGaussMeth();
		void DirectIterMeth(double epsil);
		void PrintRes();
		void PrintMatr();
		~SlarCalc();
	private:
		double x1;
		double x2;
		double x3;
		double x4;
		vector<vector<double>> a = { 
		{38, -2, 12, 15, 231},
		{4, 31, 18, 8, 125},
		{18, 9, 36, 8, 213},
		{4, 7, 1, 18, 80}};
};