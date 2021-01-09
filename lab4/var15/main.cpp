#include "Integral.h"

int main(){
    Integral a;
    printf("         |Start error| Width of h |    Error   |\n");
    printf(" --------|-----------|------------|------------|\n");
    for (double epsil = 1e-1; epsil >= 1e-10; epsil *= 0.1 ) a.Tab2(epsil);
    cout << a.Newton();
}