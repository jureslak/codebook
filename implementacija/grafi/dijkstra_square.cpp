#include "dijkstra_square.h"

vector<int> dijkstra_square(const vector<vector<pair<int, int>>>& graf, int s, int t) {
    int INF = numeric_limits<int>::max();
    int n = graf.size(), to, len;
    vector<int> d(n, INF),  prev(n);
    d[s] = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!visited[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (v == -1 || d[v] == INF) break;  // disconnected graph
        if (v == t) break;  // found shortest path to target
        visited[v] = true;

        for (auto edge : graf[v]) {
            tie(to, len) = edge;
            if (d[v] + len < d[to]) {  // if path can be improved via me
                d[to] = d[v] + len;
                prev[to] = v;
            }
        }
    }  // v d so sedaj razdalje od s do vseh, ki so bližje kot t (in t)
    vector <int> path;  // ce je d[t] == INF, je t v drugi komponenti kot s
    for (int v = t; v != s; v = prev[v])
        path.push_back(v);
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}
