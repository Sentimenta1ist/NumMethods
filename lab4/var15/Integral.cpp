#include "Integral.h"

Integral::Integral()
{

}

double Integral::Fintegral(double x)
{
    return 3 * x * x * (sin(3 * x) + x * cos(3 * x)) / 10;
}

double Integral::Fantider(double x)
{
    return x * x * x * sin(3 * x) / 10;
}

double Integral::Newton()
{
    return Fantider(b) - Fantider(a);
}

double Integral::SimpsonMethod(int number)
{
    double h = (b - a) / number;
    double answer = 0, f1, f2;
    for (int i = 0; i < number; i++) 
    {
        f1 = a + i * h;
        f2 = a + (i + 1) * h;
        answer += (f2 - f1) / 6.0 * 
            (Fintegral(f1) + 4.0 * Fintegral(0.5 * (f1 + f2)) + Fintegral(f2));
    }
    return answer;
}

void Integral::Tab1(double epsil)
{
    double h = pow(z * epsil / ((b - a) * maxder), sqr_pow);
    int number = (b - a) / h;
    curr_err = abs(SimpsonMethod(number) - Newton());
    printf(" Analz - |%10.5e|%10.6e|%10.6e|\n", epsil, (b - a) / number, curr_err);
}

void Integral::Tab2(double epsil)
{
    Tab1(epsil);
    int number = 1 / sqrt(curr_err);
    double In, I2n, Rn;
    do
    {
        In = SimpsonMethod(number);
        number *= 2;
        I2n = SimpsonMethod(number);
        Rn = 1 / (pow(2, r) - 1) * abs(I2n - In);
    } while (Rn > curr_err);
    printf(" Runge - |%10.5e|%10.6e|%10.6e|\n", curr_err, (b - a) / number, abs(I2n - Newton()));
    printf(" --------|-----------|------------|------------|\n");
}

Integral::~Integral()
{

}

