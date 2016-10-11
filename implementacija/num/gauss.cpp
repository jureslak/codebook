#include "gauss.h"

namespace {
const double eps = 1e-9;
}

int gauss(vector<vector<double>> A, vector<double>& ans) {
    int n = A.size(), m = A[0].size() - 1;

    vector<int> where(m, -1);
    for (int col = 0, row = 0; col < m && row < n; ++col) {
        int sel = row;
        for (int i = row; i < n; ++i)
            if (abs(A[i][col]) > abs(A[sel][col])) sel = i;
        if (abs(A[sel][col]) < eps) continue;
        for (int i = col; i <= m; ++i) swap(A[sel][i], A[row][i]);
        where[col] = row;

        for (int i = 0; i < n; ++i)
            if (i != row) {
                double c = A[i][col] / A[row][col];
                for (int j = col; j <= m; ++j) A[i][j] -= A[row][j] * c;
            }
        ++row;
    }  // tukaj je v A spravljen  LU razcep PA = LU.

    ans.assign(m, 0);
    for (int i = 0; i < m; ++i)
        if (where[i] != -1)
            ans[i] = A[where[i]][m] / A[where[i]][i];

    // Preverjamo rank in to, da rešitev res reši sistem
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        for (int j = 0; j < m; ++j) sum += ans[j] * A[i][j];
        if (abs(sum - A[i][m]) > eps) return -1;
    }

    return count(where.begin(), where.end(), -1);
}

double det(vector<vector<double>> a) {
    double det = 1;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int k = i;
        for (int j = i + 1; j < n; ++j)
            if (abs(a[j][i]) > abs (a[k][i]))
                k = j;
        if (abs(a[k][i]) < eps) {
            det = 0;
            break;
        }
        swap(a[i], a[k]);
        if (i != k) det = -det;
        det *= a[i][i];
        for (int j = i + 1; j < n; ++j) {
            a[i][j] /= a[i][i];
        }
        for (int j = 0; j < n; ++j) {
            if (j != i && abs(a[j][i]) > eps) {
                for (int k = i + 1; k < n; ++k) {
                    a[j][k] -= a[i][k] * a[j][i];
                }
            }
        }
    }
    return det;
}
