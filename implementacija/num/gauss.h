#ifndef IMPLEMENTACIJA_NUM_GAUSS_H_
#define IMPLEMENTACIJA_NUM_GAUSS_H_

#include <algorithm>
#include <cmath>
#include <limits>
#include <vector>

using std::abs;
using std::count;
using std::numeric_limits;
using std::swap;
using std::vector;

int gauss(vector<vector<double>> a, vector<double>& ans);
double det(vector<vector<double>> a);

#endif  // IMPLEMENTACIJA_NUM_GAUSS_H_
