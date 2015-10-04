#include "binomial.h"

int binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);
    int r = 1;
    for (int i = 0; i < k; ++i) {
        r *= n - i;
        r /= i + 1;  // deljenje se vedno izide
    }
    return r;
}

double binomial_approx(double n, double k) {
    return exp(lgamma(n+1) - lgamma(k+1) - lgamma(n-k+1));
}

vector<vector<int>> pascal_triangle(int n) {
    vector<vector<int>> ret(n, vector<int>(n, 0));
    ret[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        ret[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            ret[i][j] = ret[i-1][j] + ret[i-1][j-1];
        }
    }
    return ret;
}
