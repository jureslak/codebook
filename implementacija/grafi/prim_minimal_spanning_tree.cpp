#include "prim_minimal_spanning_tree.h"

typedef pair<int, int> pii;

int prim_minimal_spanning_tree(const vector<vector<pii>>& graf) {
    int n = graf.size(), d, u;
    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> q;  // remove greater for max-tree
    q.push({0, 0});

    int sum = 0;            // sum of the mst
    int edge_count = 0;     // stevilo dodanih povezav
    while (!q.empty()) {
        tie(d, u) = q.top();
        q.pop();

        if (visited[u]) continue;
        visited[u] = true;

        sum += d;
        if (++edge_count == n) break;  // drevo, jebeš solato

        for (const auto& edge : graf[u])
            if (!visited[edge.first])
                q.push({edge.second, edge.first});
    }  // ce zelimo drevo si shranjujemo se previous vertex.
    return sum;
}
