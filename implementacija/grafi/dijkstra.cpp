#include "dijkstra.h"

typedef pair<int, int> pii;

int dijkstra(const vector<vector<pii>>& graf, int s, int v) {
    int n = graf.size(), d, c;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<bool> visited(n, false);
    vector<int> raz(n);

    q.push({0, s});
    while (!q.empty()) {
        tie(d, c) = q.top();
        q.pop();

        if (visited[c]) continue;
        visited[c] = true;
        raz[c] = d;

        if (c == v) break;  // ce iscemo do vseh tock spremeni v --n == 0

        for (auto p : graf[c])
            if (!visited[p.first])
                q.push({d + p.second, p.first});
    }
    return raz[v];
}
