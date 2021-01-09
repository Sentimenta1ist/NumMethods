#include "Calculation.h"

/*      Variant 1
        5 * pow(x, 3) - 6 * exp(x) + 15 = 0
        roots : (-2; -1)  (4; 5)*/

int main() 
{
    Calc f1;
    cout << "\t\t\t                     ITERATIVE TABLE\n";
    cout << "\t\t\t      EPSI               RESULT              ERROR          \n";
    for (double epsi = 1e-2; epsi > 1e-14; epsi *= 1e-3)
    {
        f1.iterative_meth(epsi, -2, -1);
        cout <<"\t\t\t" << setw(10) << epsi << ' ';
        cout << setw(20) << f1.get_result_x() << ' ';
        cout << setw(20) << f1.get_error_last() << '\n';
        f1.iterative_meth(epsi, 4, 5);
        cout << "\t\t\t" << setw(10) << epsi << ' ';
        cout << setw(20) << f1.get_result_x() << ' ';
        cout << setw(20) << f1.get_error_last() << '\n';
    }

    cout << "\n\t\t\t                   NEWTON-RAPSON TABLE\n";
    cout << "\t\t\t      EPSI               RESULT              ERROR          \n";
    for (double epsi = 1e-2; epsi > 1e-14; epsi *= 1e-3)
    {
        f1.raps_meth(epsi, -2, -1);
        cout << "\t\t\t" << setw(10) << epsi << ' ';
        cout << setw(20) << f1.get_result_x() << ' ';
        cout << setw(20) << f1.get_error_last() << '\n';
        f1.raps_meth(epsi, 4, 5);
        cout << "\t\t\t" << setw(10) << epsi << ' ';
        cout << setw(20) << f1.get_result_x() << ' ';
        cout << setw(20) << f1.get_error_last() << '\n';
    }
    cout << "\n\t\t\t                    COMPARISON TABLE\n";
    cout << "\t\t\t      EPSI              ITERATIVE             NEWTON-RAPSON          \n";
    for (double epsi = 1e-2; epsi > 1e-14; epsi *= 1e-3)
    {
        f1.iterative_meth(epsi, -2, -1);
        cout << "\t\t\t" << setw(10) << epsi << ' ';
        cout << setw(20) << f1.get_numbers_of_iter() << ' ';
        f1.raps_meth(epsi, -2, -1);
        cout << setw(20) << f1.get_numbers_of_iter() << '\n';
    }
}
