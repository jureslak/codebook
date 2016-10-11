#ifndef IMPLEMENTACIJA_NUM_BISECTION_H_
#define IMPLEMENTACIJA_NUM_BISECTION_H_

#include <functional>
#include <cmath>
#include <limits>
#include <cassert>

using std::function;
using std::abs;
using std::numeric_limits;

double bisection(function<double(double)> f, double a, double b, double eps);

#endif  // IMPLEMENTACIJA_NUM_BISECTION_H_
