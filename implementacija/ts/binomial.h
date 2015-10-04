#ifndef IMPLEMENTACIJA_TS_BINOMIAL_H_
#define IMPLEMENTACIJA_TS_BINOMIAL_H_

#include <algorithm>
#include <cmath>
#include <vector>

using std::exp;
using std::lgamma;
using std::min;
using std::vector;

int binomial(int n, int k);
double binomial_approx(double n, double k);
vector<vector<int>> pascal_triangle(int n);

#endif  // IMPLEMENTACIJA_TS_BINOMIAL_H_
