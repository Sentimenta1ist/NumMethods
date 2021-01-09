#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define FUN(x) (0.2 * pow(x, 3) - pow(x, 4) - cos(x) + 1.5)
#define D_FUN(x) (0.6 * x * x - 4 * pow(x, 3) + sin(x))
#define D2_FUN(x) (1.2 * x - 12 * pow(x, 2) + cos(x))

using namespace std;

vector<pair<double, double>> roots_isolation(double a, double b);

int iteration_method(double a, double b, double epsilon, double& xn, double& err);
int chord_method(double a, double b, double epsilon, double& xn, double& err);

int main(){
    vector<pair<double, double>> pairs = roots_isolation(-2, 2);
    cout << " Iteration method:\n\n";
    cout << "   EPS         X           ERR\n";
    for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001) {
        for (auto pair : pairs) {
            double xn, err;
            int i = iteration_method(pair.first, pair.second, epsilon, xn, err);
            cout << "  " << setw(5) << epsilon << "  " << setw(12) << xn << "  " << setw(12) << err << endl;
        }
    }

    cout << "\n\n Chord method:\n\n";
    cout << "   EPS         X           ERR\n";
    for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001) {
        for (auto pair : pairs) {
            double xn, err;
            int i = chord_method(pair.first, pair.second, epsilon, xn, err);
            cout << "  " << setw(5) << epsilon << "  " << setw(12) << xn << "  " << setw(12) << err << endl;
        }
    }

    cout << "\n\n Compare:\n\n";
    cout << "   EPS      ITER         CHORD\n";
    for (double epsilon = 0.01; epsilon >= 1e-11; epsilon *= 0.001) {
        double xn, err;
        int i1 = iteration_method(pairs[0].first, pairs[0].second, epsilon, xn, err);
        int i2 = chord_method(pairs[0].first, pairs[0].second, epsilon, xn, err);
        cout << "  " << setw(5) << epsilon << "  " << setw(12) << i1 << "  " << setw(12) << i2 << endl;
    }
}

vector<pair<double, double>> roots_isolation(double a, double b) {
    vector<pair<double, double>> pairs;
    for (double i = a; i < b; i+= 0.2) {
        if (FUN(i) * FUN(i + 0.2) < 0) {
            if (D_FUN(i) * D_FUN(i + 0.2) > 0) {
                pair <double, double> one_interval;
                one_interval.first = i;
                one_interval.second = i + 0.2;
                pairs.push_back(one_interval);
            }
        }
    }
    return pairs;
}

int chord_method(double a, double b, double epsilon, double& xn, double& err) {
    double c, m1 = min(abs(D_FUN(a)), abs(D_FUN(b)));
    int i = 0;
    if ((FUN(a) * D2_FUN(a)) < 0) {
        xn = a;
        c = b;
    }
    else {
        c = a;
        xn = b;
    }
    while (abs(FUN(xn)) / m1 >= epsilon) {
        xn = xn - (FUN(xn) / (FUN(xn) - FUN(c))) * (xn - c);
        i++;
    }
    err = abs(FUN(xn) / m1);
    return i;
}

int iteration_method(double a, double b, double epsilon, double& xn, double& err) {
    double x0 = (b + a) / 2, m1 = D_FUN(a), M1 = D_FUN(b), lambda, q;
    int i = 0;
    if (abs(D_FUN(b)) < abs(D_FUN(a))) {
        m1 = D_FUN(b);
        M1 = D_FUN(a);
    }
    lambda = 1 / M1;
    q = 1 - m1 / M1;
    xn = lambda * FUN(x0);
    while (abs(xn - x0) > (1 - q) / q * epsilon) {
        x0 = xn;
        xn -= lambda * FUN(xn);
        i++;
    }
    err = q * abs(xn - x0) / (1 - q);
    return i;
}