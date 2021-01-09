#include "Realz.h"

int main(){
    cout << "New SLAR:" << endl;
    cout << "{";
    for (int i = 0; i <= siz; i++) {
        cout << setw(5) << m[0][i];
    }
    cout << "   } - (4) * 2 - (2) + (1)" << endl;
    cout << "{";
    for (int i = 0; i <= siz; i++) {
        cout << setw(5) << m[1][i];
    }
    cout << "   } - (2)" << endl;
    cout << "{";
    for (int i = 0; i <= siz; i++) {
        cout << setw(5) << m[2][i];
    }
    cout << "   } - (3)" << endl;
    cout << "{";
    for (int i = 0; i <= siz; i++) {
        cout << setw(5) << m[3][i];
    }
    cout << "   } - (1) * 4 - (2) - (3) + (4) + (1)" << endl << endl;

    cout << " Jordan-Gauss method:"; 
    print_row(JordanGauss());
    cout << " Direct Iter method: ";
    print_row(DirectIteration(1e-8));
}