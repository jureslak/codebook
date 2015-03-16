#include "bellman_ford.h"

vector<int> bellman_ford(const vector<vector<pair<int, int>>>& graf, int s) {
    int INF = numeric_limits<int>::max();
    int n = graf.size(), v, w;
    vector<int> dist(n, INF);
    vector<int> prev(n, -1);
    vector<bool> visited(n, false);

    dist[s] = 0;
    for (int i = 0; i < n-1; ++i) {  // i je trenutna dolžina poti
        for (int u = 0; u < n; ++u) {
            for (const auto& edge : graf[u]) {
                tie(v, w) = edge;
                if (dist[u] != INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < n; ++u) {  // cycle detection
        for (const auto& edge : graf[u]) {
            tie(v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v])
                return {};  // graph has a negative cycle !!
        }
    }
    return dist;
}
