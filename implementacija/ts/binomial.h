#ifndef IMPLEMENTACIJA_TS_BINOMIAL_H_
#define IMPLEMENTACIJA_TS_BINOMIAL_H_

#include <algorithm>
#include <cmath>

using std::min;
using std::exp;
using std::lgamma;

int binomial(int n, int k);
double binomial_approx(double n, double k);

#endif  // IMPLEMENTACIJA_TS_BINOMIAL_H_
