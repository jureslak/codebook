#include "bisection.h"

int sgn(double x) {
    return (x > 0.0) ? 1 : -1;
}

double bisection(function<double(double)> f, double a, double b, double eps) {
    double fa = f(a);
    double fb = f(b);
    if (b < a || sgn(fa) == sgn(fb)) return numeric_limits<double>::signaling_NaN();
    double d = b - a, c = 0.0, fc = 0.0;
    double prec = eps * d;
    while (d > prec) {
        d /= 2.0;
        c = a + d;
        fc = f(c);
        if (sgn(fa) == sgn(fc)) {
            a = c;
            fa = fc;
        }
    }
    return c;
}

