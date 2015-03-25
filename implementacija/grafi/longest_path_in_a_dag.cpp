#include "longest_path_in_a_dag.h"

int longest_path_in_a_dag(const vector<vector<pair<int, int>>>& graf, int s, int t) {
    int n = graf.size(), v, w;
    vector<int> ind(n, 0);
    vector<int> max_dist(n, -1);
    for (int i = 0; i < n; ++i)
        for (const auto& edge : graf[i])
            ind[edge.first]++;

    max_dist[s] = 0;

    queue<int> q;
    for (int i = 0; i < n; ++i)
        if (ind[i] == 0)
            q.push(i);  // topološko uredimo in gledamo maksimum

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto& edge : graf[u]) {
            tie(v, w) = edge;
            if (max_dist[u] >= 0)  // da začnemo pri s-ju, sicer bi začeli na začetku, vsi pred s -1
                max_dist[v] = max(max_dist[v], max_dist[u] + w);  // min za shortest path
            if (--ind[v] == 0) q.push(v);
        }
    }
    return max_dist[t];
}

