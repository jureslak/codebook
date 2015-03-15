#ifndef IMPLEMENTACIJA_GEOM_CLOSEST_PAIR_OF_POINTS_H_
#define IMPLEMENTACIJA_GEOM_CLOSEST_PAIR_OF_POINTS_H_

#include <complex>
#include <algorithm>
#include <limits>
#include <vector>

using std::complex;
using std::sort;
using std::vector;
using std::numeric_limits;
using std::min;

bool byx(const complex<double>& a, const complex<double>& b);
bool byy(const complex<double>& a, const complex<double>& b);

double najblizji_tocki_bf(vector<complex<double>>::iterator start,
                          vector<complex<double>>::iterator end);
double najblizji_tocki_divide(vector<complex<double>>::iterator xstart,
                              vector<complex<double>>::iterator xend,
                              const vector<complex<double>>& py);
double najblizji_tocki(const vector<complex<double>>& points);

#endif  // IMPLEMENTACIJA_GEOM_CLOSEST_PAIR_OF_POINTS_H_
