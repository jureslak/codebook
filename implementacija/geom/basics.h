#ifndef IMPLEMENTACIJA_GEOM_BASICS_H_
#define IMPLEMENTACIJA_GEOM_BASICS_H_

#include <algorithm>
#include <cmath>
#include <complex>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

#include "implementacija/ts/gcd.h"

using std::complex;
using std::numeric_limits;
using std::ostream;
using std::pair;
using std::vector;
using std::abs;
using std::min;
using std::max;
using std::tie;


struct L {
    double a, b, c;
    L();
    L(int A, int B, int C);
    L(double A, double B, double C);
    L(const complex<double>& p, const complex<double>& q);
    complex<double> normal() const;
    double value(const complex<double>& p) const;
    bool is_left(const complex<double>& p) const;
    bool operator<(const L& line) const;
    bool operator==(const L& line) const;
    friend ostream& operator<<(ostream& os, const L& line);
};
enum ITYPE : char;

double dot(const complex<double>& p, const complex<double>& q);
double cross(const complex<double>& p, const complex<double>& q);
double cross(const complex<double>& p, const complex<double>& q, const complex<double>& r);
complex<double> perp(const complex<double>& p);
int sign(double x);
double polar_angle(const complex<double>& p);
bool left_turn(const complex<double>& p, const complex<double>& q, const complex<double>& r);
double area(const complex<double>& a, const complex<double>& b, const complex<double>& c);
double area(const vector<complex<double>>& poly);
double dist_to_line(const complex<double>& p, const L& l);
double dist_to_line(const complex<double>& t, const complex<double>& p1,
                    const complex<double>& p2);
double dist_to_segment(const complex<double>& t, const complex<double>& p1,
                       const complex<double>& p2);
double great_circle_dist(const complex<double>& a, const complex<double>& b);
bool point_in_rect(const complex<double>& t, const complex<double>& p1, const complex<double>& p2);
bool point_in_triangle(const complex<double>& t, const complex<double>& a,
                       const complex<double>& b, const complex<double>& c);
ITYPE point_in_poly(const complex<double>& t, const vector<complex<double>>& poly);
pair<ITYPE, complex<double>> line_line_intersection(const L& p,
                                                    const L& q);
pair<ITYPE, complex<double>> line_segment_intersection(const L& p,
                                                       const complex<double>& u,
                                                       const complex<double>& v);
pair<ITYPE, complex<double>> segment_segment_intersection(const complex<double>& p1,
                                                          const complex<double>& p2,
                                                          const complex<double>& q1,
                                                          const complex<double>& q2);
pair<complex<double>, double> get_circle(const complex<double>& p, const complex<double>& q,
                                         const complex<double>& r);
complex<double> get_circle(const complex<double>& p, const complex<double>& q, double r);

#endif  // IMPLEMENTACIJA_GEOM_BASICS_H_
