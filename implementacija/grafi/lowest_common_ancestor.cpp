#include "lowest_common_ancestor.h"

vector<vector<int>> preprocess(const vector<int>& parent) {
    int n = parent.size();
    int logn = 1;
    while (1 << ++logn < n);
    vector<vector<int>> P(n, vector<int>(logn, -1));

    for (int i = 0; i < n; i++)  // prvi prednik za i je parent[i]
        P[i][0] = parent[i];

    for (int j = 1; 1 << j < n; j++)
        for (int i = 0; i < n; i++)
            if (P[i][j - 1] != -1)                // P[i][j] = 2^j-ti prednik i-ja
                P[i][j] = P[P[i][j - 1]][j - 1];
    return P;
}

int level_internal(const vector<int>& parent, vector<int>& L, int v) {
    if (L[v] != -1) return L[v];
    return L[v] = (parent[v] == v) ? 0 : level_internal(parent, L, parent[v]) + 1;
}

vector<int> levels(const vector<int>& parent) {
    vector<int> L(parent.size(), -1);
    for (size_t i = 0; i < parent.size(); ++i) level_internal(parent, L, i);
    return L;
}

// supply returned values of `levels` and `preprocess` for L and P
int find_lca(const vector<int>& parent, int u, int v,
             const vector<vector<int>>& P, const vector<int>& L) {
    if (L[u] < L[v])  // if u is on a higher level than v then we swap them
        swap(u, v);

    int log = 1;
    while (1 << ++log <= L[u]);
    log--;  // we compute the value of [log(L[u)]

      for (int i = log; i >= 0; i--)     // we find the ancestor of node u situated on
          if (L[u] - (1 << i) >= L[v])   // the same level as v using the values in P
              u = P[u][i];

      if (u == v) return u;

      for (int i = log; i >= 0; i--)  // we compute LCA(u, v) using the values in P
          if (P[u][i] != -1 && P[u][i] != P[v][i])
              u = P[u][i], v = P[v][i];

      return parent[u];
}
