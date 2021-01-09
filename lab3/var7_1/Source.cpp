#include "Meth.h"

int main(){
	SlarCalc Jordan;
	SlarCalc Iter;
	Jordan.PrintMatr();
	Jordan.JordanGaussMeth();
	Iter.DirectIterMeth(1e-4);
	cout << "\n JORDAN_GAUSS: ";
	Jordan.PrintRes();
	cout << "\n  DIRECT_ITER: ";
	Iter.PrintRes();
}