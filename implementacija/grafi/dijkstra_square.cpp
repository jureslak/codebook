#include "dijkstra_square.h"

vector<int> dijkstra_square(const vector<vector<pair<int, int>>>& graf, int s, int t) {
    int INF = numeric_limits<int>::max();
    int n = graf.size(), to, len;
    vector<int> dist(n, INF),  prev(n);
    dist[s] = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int u = -1;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (u == -1 || dist[j] < dist[u]))
                u = j;                         // vertex with minimum dist
        if (u == -1 || dist[u] == INF) break;  // disconnected graph
        if (u == t) break;  // found shortest path to target
        visited[u] = true;

        for (const auto& edge : graf[u]) {
            tie(to, len) = edge;
            if (dist[u] + len < dist[to]) {  // if path can be improved via me
                dist[to] = dist[u] + len;
                prev[to] = u;
            }
        }
    }  // v dist so sedaj razdalje od s do vseh, ki so bližje kot t (in t)
    vector<int> path;  // ce je dist[t] == INF, je t v drugi komponenti kot s
    for (int v = t; v != s; v = prev[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
