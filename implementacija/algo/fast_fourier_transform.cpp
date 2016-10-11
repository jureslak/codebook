#include "fast_fourier_transform.h"

typedef complex<double> cd;

void fft(vector<cd>& a, bool invert) {
    double pi = 3.1415926535897932384626433832795;
    int n = static_cast<int>(a.size());
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0, j = 0; i < n; i += 2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * pi / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; i < n / 2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) a[i] /= 2, a[i + n / 2] /= 2;
        w *= wn;
    }
}

vector<int> multiply_poly(const vector<int>& a, const vector<int>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    size_t n = 1;
    while (n < max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize(n), fb.resize(n);

    fft(fa, false), fft(fb, false);
    for (size_t i = 0; i < n; ++i) fa[i] *= fb[i];
    fft(fa, true);

    vector<int> res(n);
    for (size_t i = 0; i < n; ++i) res[i] = static_cast<int>(fa[i].real() + 0.5);
    while (res.back() == 0) res.pop_back();
    return res;
}

vector<int> multiply_integer(const vector<int>& a, const vector<int>& b) {
    vector<int> res = multiply_poly(a, b);
    int osnova = 10;
    int carry = 0;
    for (size_t i = 0; i < res.size(); ++i) {
        res[i] += carry;
        carry = res[i] / osnova;
        res[i] %= osnova;
    }
    while (carry > 0) {
        res.push_back(carry % osnova);
        carry /= osnova;
    }
    return res;
}
