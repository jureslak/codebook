#ifndef IMPLEMENTACIJA_ALGO_FAST_FOURIER_TRANSFORM_H_
#define IMPLEMENTACIJA_ALGO_FAST_FOURIER_TRANSFORM_H_

#include <complex>
#include <vector>
#include <cmath>
#include <algorithm>

using std::complex;
using std::vector;
using std::cos;
using std::sin;
using std::max;

void fft(vector<complex<double>>& a, bool invert);
vector<int> multiply_poly(const vector<int>& a, const vector<int>& b);
vector<int> multiply_integer(const vector<int>& a, const vector<int>& b);

#endif  // IMPLEMENTACIJA_ALGO_FAST_FOURIER_TRANSFORM_H_
