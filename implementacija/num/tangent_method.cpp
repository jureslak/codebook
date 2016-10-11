#include "tangent_method.h"

double tangent_method(function<double(double)> f, function<double(double)> df, double x0,
                      double eps, int max_iterations) {
    double xn = x0;
    for (int i = 0; i < max_iterations; ++i) {
        x0 = xn;
        xn = x0 - f(x0) / df(x0);
        printf("%.6f", xn);
        if (abs(x0-xn) < eps * abs(xn)) break;
    }
    return xn;
}

