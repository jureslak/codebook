#include "longest_increasing_subsequence.h"

vector<int> longest_increasing_subsequence(const vector<int>& a) {
    vector<int> p(a.size()), b;
    int u, v;

    if (a.empty()) return {};
    b.push_back(0);

    for (size_t i = 1; i < a.size(); i++) {
        if (a[b.back()] < a[i]) {
            p[i] = b.back();
            b.push_back(i);
            continue;
        }

        for (u = 0, v = b.size()-1; u < v;) {
            int c = (u + v) / 2;
            if (a[b[c]] < a[i]) u = c + 1;
            else v = c;
        }

        if (a[i] < a[b[u]]) {
            if (u > 0) p[i] = b[u-1];
            b[u] = i;
        }
    }

    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = a[v];
    return b;       // b[u] = v, če želiš indekse, ali ce ima a neinteger elemente
}

vector<int> longest_increasing_subsequence_square(const vector<int>& a) {
    if (a.size() == 0) return {};
    int max_length = 1, best_end = 0;
    int n = a.size();
    vector<int> m(n, 0), prev(n, -1);  // m[i] = dolzina lis, ki se konca pri i
    m[0] = 1;
    prev[0] = -1;

    for (int i = 1; i < n; i++) {
        m[i] = 1;
        prev[i] = -1;

        for (int j = i-1; j >= 0; --j) {
            if (m[j] + 1 > m[i] && a[j] < a[i]) {
                m[i] = m[j] + 1;
                prev[i] = j;
            }

            if (m[i] > max_length) {
                best_end = i;
                max_length = m[i];
            }
        }
    }
    vector<int> lis;
    for (int i = best_end; i != -1; i = prev[i]) lis.push_back(a[i]);
    reverse(lis.begin(), lis.end());
    return lis;
}
