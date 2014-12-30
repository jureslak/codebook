#include "articulation_points_and_bridges.h"

namespace {
vector<int> low;
vector<int> dfs_num;
vector<int> parent;
}

void articulation_points_and_bridges_internal(int u, const vector<vector<int>>& G,
        vector<bool>& articulation_points_map, vector<pair<int, int>>& bridges) {
    static int dfs_num_counter = 0;
    low[u] = dfs_num[u] = ++dfs_num_counter;
    int children = 0;
    for (int v : G[u]) {
        if (dfs_num[v] == -1) {  // unvisited
            parent[v] = u;
            children++;

            articulation_points_and_bridges_internal(v, G, articulation_points_map, bridges);
            low[u] = min(low[u], low[v]);  // update low[u]

            if (parent[u] == -1 && children > 1)  // special root case
                articulation_points_map[u] = true;
            else if (parent[u] != -1 && low[v] >= dfs_num[u])  // articulation point
                articulation_points_map[u] = true;  // assigned more than once
            if (low[v] > dfs_num[u])               // bridge
                bridges.push_back({u, v});
        } else if (v != parent[u]) {
            low[u] = min(low[u], dfs_num[v]);  // update low[u]
        }
    }
}

void articulation_points_and_bridges(int n, int m, const int E[][2],
        vector<int>& articulation_points, vector<pair<int, int>>& bridges) {
    vector<vector<int>> G(n);
    for (int i = 0; i < m; ++i) {
        int a = E[i][0], b = E[i][1];
        G[a].push_back(b);
        G[b].push_back(a);
    }

    low.assign(n, -1);
    dfs_num.assign(n, -1);
    parent.assign(n, -1);

    vector<bool> articulation_points_map(n, false);
    for (int i = 0; i < n; ++i)
        if (dfs_num[i] == -1)
            articulation_points_and_bridges_internal(i, G, articulation_points_map, bridges);

    for (int i = 0; i < n; ++i)
        if (articulation_points_map[i])
            articulation_points.push_back(i);  // actually return only articulation points
}

