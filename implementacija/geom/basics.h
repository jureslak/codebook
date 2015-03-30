#ifndef IMPLEMENTACIJA_GEOM_BASICS_H_
#define IMPLEMENTACIJA_GEOM_BASICS_H_

#include "basics_util.h"

const double pi = M_PI;
const double eps = 1e-9;
const double inf = numeric_limits<double>::infinity();

enum ITYPE : char { OK, NO, EQ };
typedef complex<double> P;

template<typename T>
struct line_t {  // premica, dana z enačbo ax + by = c ali z dvema točkama
    double a, b, c;  // lahko tudi int
    line_t() : a(0), b(0), c(0) {}
    line_t(int A, int B, int C) {
        if (A < 0 || (A == 0 && B < 0)) a = -A, b = -B, c = -C;
        else a = A, b = B, c = C;
        int d = gcd(gcd(abs(a), abs(b)), abs(c));  // same sign as A, if nonzero, else B, else C
        if (d == 0) d = 1;                    // in case of 0 0 0 input
        a /= d;
        b /= d;
        c /= d;
    }
    line_t(T A, T B, T C) {
        if (A < 0 || (A == 0 && B < 0)) a = -A, b = -B, c = -C;
        else a = A, b = B, c = C;
    }
    line_t(const P& p, const P& q) : line_t(imag(q-p), real(p-q), cross(p, q)) {}
    P normal() const { return {a, b}; }
    double value(const P& p) const { return dot(normal(), p) - c; }
    bool operator<(const line_t<T>& line) const {  // da jih lahko vržemo v set, če T = int
        if (a == line.a) {
            if (b == line.b) return c < line.c;
            return b < line.b;
        }
        return a < line.a;
    }
    bool operator==(const line_t<T>& line) const {
        return cross(normal(), line.normal()) < eps && c*line.b == b*line.c;
    }
};
template<typename T>
ostream& operator<<(ostream& os, const line_t<T>& line) {
    os << line.a << "x + " << line.b << "y == " << line.c; return os;
}

typedef line_t<double> L;

#endif  // IMPLEMENTACIJA_GEOM_BASICS_H_
