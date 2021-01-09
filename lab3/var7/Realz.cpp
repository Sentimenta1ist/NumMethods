#include "Realz.h"

vector<double> DivRow(vector<double> r, double num) {
    vector<double> a = r;
    for (int i = 0; i < size(a); i++) {
        a[i] = a[i] / num;
    }
    return a;
}

vector<vector<double>> m = {
    {38, -2, 12, 15, 231},
    {4, 31, 18, 8, 125},
    {18, 9, 36, 8, 213},
    {4, 7, 1, 18, 80}
};

void print_row(vector<double> res) {
    for (int i = 0; i < size(res); i++) {
        printf(" %15.10lf ", res[i]);
    }
    cout << endl;
}

vector<double> JordanGauss() {
    vector<vector<double>> tmp = m;
    for (int i = 0; i < size(tmp); i++) {
        double main_el = tmp[i][i];
        for (int i1 = 0; i1 < i; i1++) {
            double row = tmp[i1][i];
            for (int j = 0; j < size(tmp[i]); j++) {
                tmp[i1][j] -= row * tmp[i][j] / main_el;
            }
        }
        for (int i1 = i + 1; i1 < size(tmp); i1++) {
            double row = tmp[i1][i];
            for (int j = 0; j < size(tmp[i]); j++) {
                tmp[i1][j] -= row * tmp[i][j] / main_el;
            }
        }
        tmp[i] = DivRow(tmp[i], main_el);
    }
    return { tmp[0][4], tmp[1][4], tmp[2][4], tmp[3][4] };
}

vector<double> DirectIteration(double epsilon) {
    vector <double> results(siz);
    vector<vector<double>> tmp;
    double q_max = 0, q = 0;
    for (int i = 0; i < size(m); i++) {
        vector<double> tmp_line;
        q = 0;
        for (int j = 0; j < size(m); j++) {
            if (j == i) {
                tmp_line.push_back(m[i][siz] / m[i][i]);
                results[i] = m[i][siz] / m[i][i];
            }
            else{
                q += abs(m[i][j] / m[i][i]);
                tmp_line.push_back(m[i][j] / m[i][i]);
            }
        }
        tmp.push_back(tmp_line);
        if (q > q_max) {
            q_max = q;
        }
    }
    q = q_max;
    double prev = 0;
    while (abs(results[0] - prev) > (1 - q) / q * epsilon) {
        vector <double> tmp_vector;
        prev = results[0];
        for (int i = 0; i < size(tmp); i++) {
            double tmp_value = 0;
            for (int j = 0; j < size(tmp[i]); j++) {
                if (i == j) {
                    continue;
                }
                tmp_value += results[j] * tmp[i][j];
            }
            tmp_vector.push_back(tmp[i][i] - tmp_value);
        }
        results = tmp_vector;
    }
    return results;
}