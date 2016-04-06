#include "knuth_morris_pratt.h"

vector<int> compute_failure_function(const string& p) {
	int m = p.size();
    vector<int> ff(m, 0);
    for (int k = 0, i = 1; i < m; ++i) {
        while (k > 0 && p[i] != p[k]) k = ff[k-1];
        if (p[i] == p[k]) k++;
        ff[i] = k;
    }
    return ff;
}

int knuth_morris_pratt(const string& s, const string& p, const vector<int>& ff, int start) {
    int k = 0, n = s.size(), m = p.size();
    for (int i = start; i < n; i++) {
        while (k > 0 && p[k] != s[i]) k = ff[k-1];
        if (s[i] == p[k]) k++;
        if (k == m) return i - k + 1;
    }
    return -1;
}

int knuth_morris_pratt(const string& s, const string& p) {
    vector<int> ff = compute_failure_function(p);
    return knuth_morris_pratt(s, p, ff, 0);
}

vector<int> find_all_occurences(const string& s, const string& p) {
    vector<int> ff = compute_failure_function(p), result;
    int i = -1;
    while ((i = knuth_morris_pratt(s, p, ff, i + 1)) != -1) {
        result.push_back(i);  // or do something else
    }
    return result;
}
vector<int> find_non_overlaping_occurences(const string& s, const string& p) {
    vector<int> ff = compute_failure_function(p), result;
    int i = -p.size();
    while ((i = knuth_morris_pratt(s, p, ff, i + p.size())) != -1) {
        result.push_back(i);  // or do something else
    }
    return result;
}
int minimal_period(const string& s) {
    int n = s.size();
    vector<int> ff = compute_failure_function(s);
    int candidate = n - ff.back();
    if (n % candidate == 0) return candidate;
    return n;
}
