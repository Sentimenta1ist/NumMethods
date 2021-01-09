#include <iostream>
#include <iomanip> 
#include <vector>
using namespace std;
int n = 4;

vector <vector <double>> slar = {
	{552, 520, 808, 244, 1506},	
	{520, 1687, 997, 601, 4764},	
	{808, 997, 1391, 651, 2640},	
	{244, 601, 651, 524, 1398},
};

void PrintRes(vector <double> res) {
    cout << "\n ANSWERS : ";
    printf("| x1: %.15lf | x2: %.15lf | x3 %.15lf | x4 %.15lf |\n", res[0], res[1], res[2], res[3]);
}

void PrintMatrix(vector<vector<double>> res) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %9.2lf ", res[i][j]);
        cout << endl;
    }
}

void Gauss() {
    vector<double> res(n);
    for (int i = 0; i < n; i++) res.push_back(0);
    for (int k = 0; k < n; k++){
        for (int j = k + 1; j < n; j++){
            double div = slar[j][k] / slar[k][k];
            for (int i = k; i <= n; i++)
                slar[j][i] = slar[j][i] - div * slar[k][i];
        }
    }
    for (int k = n - 1; k >= 0; k--){
        double tmp = 0;
        for (int j = k + 1; j < n; j++)
            tmp += slar[k][j] * res[j];
        res[k] = (slar[k][4] - tmp) / slar[k][k];
    }
    PrintRes(res);
}

void Seidel(double eps) {
    vector<vector<double>> beta_view;
    vector<double> res(n);
    for (int i = 0; i < n; i++) res.push_back(0);
    double q = 0;
    for (int i = 0; i < n; i++) {
        vector <double> tmp;
        double q_1 = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                tmp.push_back(slar[i][n] / slar[i][i]);
                res[i] = slar[i][n] / slar[i][i];
                continue;
            }
            double ai = slar[i][j] / slar[i][i];
            tmp.push_back(-ai);
            q_1 += abs(ai);
        }
        beta_view.push_back(tmp);
        if ((abs(q_1) > q) && (abs(q_1) < 1)) q = q_1;
    }
    cout << q;
    double before;
    do {
        before = res[0];
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                sum += res[j] * beta_view[i][j];
            }
            res[i] = beta_view[i][i] + sum;
        }
    } while (abs(res[0] - before) > (1 - q) / q * eps);
    PrintRes(res);
}
    
int main(){
    cout << "\n SLAR : A^T * A | A^T * b \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %9.2lf ", slar[i][j]);
        printf(" | % 9.2lf ", slar[i][n]);
        cout << endl;
    }
    cout << "\n GAUSS METHOD:";
    Gauss();
    cout << "\n SEIDEL METHOD:";
    Seidel(1e-10);
}