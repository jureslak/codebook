#include "knuth_morris_pratt.h"

vector<int> compute_failure_function(const string& p) {
    int k = -1, i = 1, m = p.size();
    vector<int> ff(m, k);
    for (i = 1; i < m; i++) {
        while (k > -1 && p[k+1] != p[i]) k = ff[k];
        if (p[i] == p[k+1]) k++;
        ff[i] = k;
    }
    return ff;
}

int knuth_morris_pratt(const string& s, const string& p, const vector<int>& ff, int start) {
    int k = -1;
    int n = s.size(), m = p.size();
    for (int i = start; i < n; i++) {
        while (k > -1 && p[k+1] != s[i]) k = ff[k];
        if (s[i] == p[k+1]) k++;
        if (k == m-1) return i-k;
    }
    return -1;
}

int knuth_morris_pratt(const string& s, const string& p) {
    vector<int> ff = compute_failure_function(p);
    return knuth_morris_pratt(s, p, ff, 0);
}

vector<int> find_all_occurences(const string& s, const string & p) {
    vector<int> ff = compute_failure_function(p), result;
    int i = -1;
    while ((i = knuth_morris_pratt(s, p, ff, i+1)) != -1) {
        result.push_back(i);  // or do something else
    }
    return result;
}
vector<int> find_non_overlaping_occurences(const string& s, const string & p) {
    vector<int> ff = compute_failure_function(p), result;
    int i = -p.size();
    while ((i = knuth_morris_pratt(s, p, ff, i+p.size())) != -1) {
        result.push_back(i);  // or do something else
    }
    return result;
}
