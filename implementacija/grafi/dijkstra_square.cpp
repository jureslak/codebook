#include "dijkstra_square.h"

vector<int> dijkstra_square(const vector<vector<pair<int, int>>>& graf, int s, int t) {
    int INF = numeric_limits<int>::max();
    int n = graf.size(), to, len;
    vector<int> dist(n, INF),  prev(n);
    dist[s] = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (v == -1 || dist[j] < dist[v]))
                v = j;                         // vertex with minimum dist
        if (v == -1 || dist[v] == INF) break;  // disconnected graph
        if (v == t) break;  // found shortest path to target
        visited[v] = true;

        for (const auto& edge : graf[v]) {
            tie(to, len) = edge;
            if (dist[v] + len < dist[to]) {  // if path can be improved via me
                dist[to] = dist[v] + len;
                prev[to] = v;
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
