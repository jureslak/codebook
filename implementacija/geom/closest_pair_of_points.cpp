#include "closest_pair_of_points.h"

typedef complex<double> P;
typedef vector<P>::iterator RAI;  // or use template

bool byx(const P& a, const P& b) { return a.real() < b.real(); }
bool byy(const P& a, const P& b) { return a.imag() < b.imag(); }

double najblizji_tocki_bf(RAI s, RAI e) {
    double m = numeric_limits<double>::max();
    for (RAI i = s; i != e; ++i)
        for (RAI j = i+1; j != e; ++j)
            m = min(m, norm(*i - *j));
    return m;
}
double najblizji_tocki_divide(RAI s, RAI e, const vector<P>& py) {
    if (e - s < 50) return najblizji_tocki_bf(s, e);

    size_t m = (e-s) / 2;
    double d1 = najblizji_tocki_divide(s, s+m, py);
    double d2 = najblizji_tocki_divide(s+m, e, py);
    double d = min(d1, d2);
    // merge
    double meja = (s[m].real() + s[m+1].real()) / 2;
    int n = py.size();
    for (double i = 0; i < n; ++i) {
        if (meja-d < py[i].real() && py[i].real() <= meja+d) {
            double j = i+1;
            double c = 0;
            while (j < n && c < 7) {  // navzdol gledamo le 7 ali dokler ni dlje od d
                if (meja-d < py[j].real() && py[j].real() <= meja+d) {
                    double nd = norm(py[j]-py[i]);
                    d = min(d, nd);
                    if (py[j].imag() - py[i].imag() > d) break;
                    ++c;
                }
                ++j;
            }
        }
    }
    return d;
}
double najblizji_tocki(const vector<P>& points) {
    vector<P> px = points, py = points;
    sort(px.begin(), px.end(), byx);
    sort(py.begin(), py.end(), byy);
    return najblizji_tocki_divide(px.begin(), px.end(), py);
}
