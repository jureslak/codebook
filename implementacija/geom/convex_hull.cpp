#include "convex_hull.h"

typedef complex<double> P;  // ali int

bool compare(const P& a, const P& b, const P& m) {
    double det = cross(a, m, b);
    if (abs(det) < eps) return abs(a-m) < abs(b-m);
    return det < 0;
}

vector<P> convex_hull(vector<P>& points) {  // vector is modified
    if (points.size() <= 2) return points;
    P m = points[0]; int mi = 0;
    int n = points.size();
    for (int i = 1; i < n; ++i) {
        if (points[i].imag() < m.imag() ||
           (points[i].imag() == m.imag() && points[i].real() < m.real())) {
            m = points[i];
            mi = i;
        }
    }   // m = spodnja leva

    swap(points[0], points[mi]);
    sort(points.begin()+1, points.end(),
         [&m](const P& a, const P& b) { return compare(a, b, m); });

    vector<P> hull;
    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < n; ++i) {  // tocke, ki so na ovojnici spusti, ce jih hoces daj -eps
        while (hull.size() >= 2 && cross(hull.end()[-2], hull.end()[-1], points[i]) < eps) {
            hull.pop_back();  // right turn
        }
        hull.push_back(points[i]);
    }

    return hull;
}
