#include "dijkstra.h"

typedef pair<int, int> pii;

int dijkstra(const vector<vector<pii>>& graf, int s, int t) {
    int n = graf.size(), d, u;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<bool> visited(n, false);
    vector<int> dist(n);

    q.push({0, s});  // {cena, tocka}
    while (!q.empty()) {
        tie(d, u) = q.top();
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;
        dist[u] = d;

        if (u == t) break;  // ce iscemo do vseh tock spremeni v --n == 0

        for (const auto& p : graf[u])
            if (!visited[p.first])
                q.push({d + p.second, p.first});
    }
    return dist[t];
}
