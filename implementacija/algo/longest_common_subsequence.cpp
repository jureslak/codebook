#include "longest_common_subsequence.h"

// lahko pridemo na O(n sqrt(n))
vector<int> longest_common_subsequence(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> c(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i-1] == b[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i][j-1], c[i-1][j]);
    vector<int> sequence;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            sequence.push_back(a[i-1]);
            i--; j--;
        } else if (c[i][j-1] > c[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

//  O(n) prostora, lahko tudi zgornjo verzijo, ce je dovolj spomina.
int longest_common_subsequence_length(const vector<int>& a, const vector<int>& b) {
    int n = a.size(), m = b.size();  // po moznosi transponiraj tabelo, ce je malo spomina
    vector<vector<int>> c(2, vector<int>(m + 1, 0));
    bool f = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            if (a[i-1] == b[j-1])
                c[f][j] = c[!f][j-1] + 1;
            else
                c[f][j] = max(c[f][j-1], c[!f][j]);
        f = !f;
    }
    return c[!f][m];
}
