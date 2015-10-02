#include "binomial.h"

int binomial(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    k = min(k, n - k);
    int r = 1;
    for (int i = 0; i < k; ++i) {
        r *= n - i;
        r /= i + 1;
    }
    return r;
}

double binomial_approx(double n, double k) {
    return exp(lgamma(n+1) - lgamma(k+1) - lgamma(n-k+1));
}
