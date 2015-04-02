#include "maximum_subarray.h"

int maximum_subarray(const vector<int>& a) {  // glej komentarje ce ne dovolimo prazne vsote
    int max_ending_here = 0, max_so_far = 0;  // A[0]
    for (int x : a) {  // a[1:]
        max_ending_here = max(0, max_ending_here + x);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

vector<int> maximum_subarray_extract(const vector<int>& a) {
    int max_ending_here = 0, max_so_far = 0;
    int idx_from = 0, total_to = 0, total_from = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (max_ending_here + a[i] > 0) {
            max_ending_here += a[i];
        } else {
            idx_from = i + 1;
        }
        if (max_ending_here > max_so_far) {
            total_from = idx_from;
            total_to = i + 1;
            max_so_far = max_ending_here;
        }
    }
    return vector<int>(a.begin() + total_from, a.begin() + total_to);
}

int maximum_subarray(const vector<int>& a, int k) {  // k = 1 ... n(n-1)/2
    int n = a.size();
    vector<int> s(n+1, 0);
    vector<pair<int, int>> p(n+1);
    priority_queue<tuple<int, int, int>> q;
    for (int i = 0, m = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
        if (s[m] > s[i]) m = i;
        p[i+1] = make_pair(s[i+1], i+1);
        q.push(make_tuple(s[i+1]-s[m], i+1, m));
    }
    sort(p.begin(), p.end());
    vector<int> ss(n+1);
    for (int i = 0; i <= n; ++i)
        ss[p[i].second] = i;

    int v = -1, i, j;
    for (int l = 1; l <= k; ++l) {
        tie(v, i, j) = q.top();
        q.pop();

        for (int m = ss[j] + 1; m <= n; ++m) {
            if (p[m].second < i) {
                q.push(make_tuple(s[i]-p[m].first, i, p[m].second));
                break;
            }
        }
    }
    return v;
}
