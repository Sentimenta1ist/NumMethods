#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct point {
    double a;
    double b;
};

struct result {
    double xn;
    int count;
    double err;
};

double f(double x) {
    return (x * x - sin(x)) / (cos(x) - 2) + 1;
}

double df(double x) {
    return ((x * x - sin(x)) * sin(x) + (2 * x - cos(x)) * (cos(x) - 2)) / (cos(x) * cos(x) - 4 * cos(x) + 4);
}

double d2f(double x) {
    return (x * x - sin(x)) * (cos(x) / (cos(x) * cos(x) - 4 * cos(x) + 4) +
        2 * sin(x) * sin(x) / (pow((cos(x) - 2), 3))) +
        2 * sin(x) * (2 * x - cos(x)) / (cos(x) * cos(x) - 4 * cos(x) + 4) + (sin(x) + 2) / (cos(x) - 2);
}

vector <point> intervals(double x1,double x2) {
    vector <point> res;
    for (double i = x1; i < x2; i += 0.1) {
        if (f(i) * f(i + 0.1) < 0) {
            if (df(i) * df(i + 0.1) > 0) {
                point dot;
                dot.a = i;
                dot.b = i + 0.1;
                res.push_back(dot);
            }
        }
    }
    return res;
}

vector<result> Secant_Method(double eps, vector<point> intervals) {
    vector <result> res;
    result res_one;
    for (const auto& one : intervals) {
        double a = one.a, b = one.b, c, xn;
        int count = 0;
        double m1 = min(abs(df(a)), abs(df(b)));
        if ((f(a) * d2f(a)) > 0) {
            c = a;
            xn = b;
        }
        else {
            c = b;
            xn = a;
        }
        do {
            xn = xn - (f(xn) / (f(xn) - f(c))) * (xn - c);
            count++;
        } while (abs(f(xn)) / m1 > eps);
        res_one.xn = xn;
        res_one.count = count;
        res_one.err = abs(f(xn) / m1);
        res.push_back(res_one);
    }
    return res;
}

vector<result> Interval_Method(double eps, vector<point> intervals) {
    vector<result> res;
    result res_one;
    for (const auto &one : intervals) {
        double a = one.a, b = one.b;
        double x0 = (a + b) / 2;
        double M1, m1, xn, lambda, q;
        if (abs(df(a)) < (abs(df(b)))) {
            m1 = df(a);
            M1 = df(b);
        }
        else {
            m1 = df(b);
            M1 = df(a);
        }
        lambda = 1 / M1;
        q = 1 - m1 / M1;
        xn = x0;
        int count = 0;
        do {
            x0 = xn;
            xn = x0 - lambda * f(x0);
            count++;
        } while (abs(xn - x0) > (1 - q) / q * eps);
        res_one.xn = xn;
        res_one.count = count;
        res_one.err = abs(q * abs(xn - x0) / (1 - q));
        res.push_back(res_one);
    }
    return res;
}



int main(){
    vector<point> this_intervals = intervals(-3.0, 3.0); //interval by eyes 

    cout << "             SECANT METHOD             " << endl;
    cout << "---------------------------------------" << endl;
    cout << "|  eps|             xn|            err|" << endl;
    cout << "|-----|---------------|---------------|" << endl;
    for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
        vector<result> secant_ans = Secant_Method(eps, this_intervals);
        for (const auto& ans : secant_ans) {
            cout << '|' << setw(5) << eps << '|' << setw(15) << ans.xn << '|' << setw(15) << ans.err << "|\n";
        }
    }
    cout << "---------------------------------------" << endl << endl;


    cout << "            ITERATIVE METHOD           " << endl;
    cout << "---------------------------------------" << endl;
    cout << "|  eps|             xn|            err|" << endl;
    cout << "|-----|---------------|---------------|" << endl;
    for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
        vector<result> secant_ans =Interval_Method(eps, this_intervals);
        for (const auto& ans : secant_ans) {
            cout << '|' << setw(5) << eps << '|' << setw(15) << ans.xn << '|' << setw(15) << ans.err << "|\n";
        }
    }
    cout << "---------------------------------------" << endl << endl;

    cout << "                Comparison             " << endl;
    cout << "---------------------------------------" << endl;
    cout << "|  eps|  count by iter|count by secant|" << endl;
    cout << "|-----|---------------|---------------|" << endl;
    for (double eps = 1e-2; eps >= 1e-14; eps *= 1e-3) {
        vector<result> iter_res = Interval_Method(eps, this_intervals);
        vector<result> sec_res = Secant_Method(eps, this_intervals);
        cout << '|' << setw(5) << eps << '|' << setw(15) << iter_res[0].count << '|' << setw(15) << sec_res[0].count << "|\n";
    }
    cout << "---------------------------------------" << endl << endl;
    cout << "          Secant method faster!        " << endl << endl;
}
