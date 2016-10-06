#include "z_function.h"

vector<int> z_function(const string& s) {
    int n = s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}
int match(const string& s, const string& p) {
    string t = p + '#' + s;  // # does not appear in s or p
    vector<int> z = z_function(t);
    int n = s.size(), m = p.size();
    for (int i = 0; i < n; ++i)
        if (z[i+m+1] == m)
            return i;
    return -1;
}
int minimal_period_zf(const string& s) {
    int n = s.size();
    vector<int> z = z_function(s);
    for (int i = 1; i < n; ++i)
        if (n % i == 0 && i + z[i] == n)  // ce ni pogoja n % i == 0 najdemo tudi necele periode
            return i;  // če najdemo vse take i, najdemo vse periode
    return n;
}
