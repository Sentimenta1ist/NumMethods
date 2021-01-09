#include "Methods.h"

int main(){
    printf(" ---   Iterative method   ---\n\n");
    printf("   eps            result        errror\n");
    printf("x1:\n");
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
        results this_res = my_iterative_method(eps, -2, -1);
        printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);
    }   
    printf("x2:\n");     
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
            results this_res = my_iterative_method(eps, -0.5, 0);
            printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);   
    }
    printf("x3:\n");  
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
            results this_res = my_iterative_method(eps, 0.5, 1);
            printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);  
    }

    printf("\n\n ---   Newton-Raphson method   ---\n\n");
    printf("   eps            result        errror\n");
    printf("x1:\n");
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
        results this_res = my_newton_method(eps, -2, -1);
        printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);
    }
    printf("x2:\n");
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
        results this_res = my_newton_method(eps, -0.5, 0);
        printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);
    }
    printf("x3:\n");
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
        results this_res = my_newton_method(eps, 0.5, 1);
        printf("%e %14.10lf %e\n", eps, this_res.result, this_res.error);
    }

    printf("\n\n                      ---   Comparison   ---\n\n");
    printf("                       iterative         newton        \n");
    for (double eps = 1e-2; eps >= 1e-11; eps *= 1e-3) {
        results this_res1 = my_iterative_method(eps, -2, -1);
        results this_res2 = my_newton_method(eps, -2, -1);
        printf("%e %15d %15d\n", eps, this_res1.amount, this_res2.amount);
    }
}
