#include "kruskal_minimal_spanning_tree.h"

namespace {
vector<int> parent;
vector<int> rank;
}

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

bool unija(int x, int y) {
    int xr = find(x);
    int yr = find(y);

    if (xr == yr) return false;
    if (rank[xr] < rank[yr]) {     // rank lahko tudi izpustimo, potem samo parent[xr] = yr;
        parent[xr] = yr;
    } else if (rank[xr] > rank[yr]) {
        parent[yr] = xr;
    } else {
        parent[yr] = xr;
        rank[xr]++;
    }
    return true;
}

int kruskal_minimal_spanning_tree(int n, int m, int E[][3]) {
    rank.assign(n, 0);
    parent.assign(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i) edges.emplace_back(E[i][0], E[i][1], E[i][2]);
    sort(edges.begin(), edges.end(),
        [] (const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) < get<2>(b);
        });

    int sum = 0, a, b, c, edge_count = 0;
    for (int i = 0; i < m; ++i) {  // samo toliko povezav imamo
        tie(a, b, c) = edges[i];
        if (unija(a, b)) {
            sum += c;
            edge_count++;
        }
        if (edge_count == n - 1) break;
    }
    return sum;
}
