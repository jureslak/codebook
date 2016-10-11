#ifndef IMPLEMENTACIJA_NUM_TANGENT_METHOD_H_
#define IMPLEMENTACIJA_NUM_TANGENT_METHOD_H_

#include <functional>
#include <cmath>

using std::function;
using std::abs;

double tangent_method(function<double(double)> f, function<double(double)> df, double x0,
                      double prec, int max_iterations);

#endif  // IMPLEMENTACIJA_NUM_TANGENT_METHOD_H_
