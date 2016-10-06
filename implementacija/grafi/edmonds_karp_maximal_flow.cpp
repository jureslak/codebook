#include "edmonds_karp_maximal_flow.h"

namespace {
const int INF = numeric_limits<int>::max();
struct triple { int u, p, m; };
}

int edmonds_karp_maximal_flow(const vector<vector<int>>& capacity, int s, int t) {
    int n = capacity.size();
    vector<vector<int>> flow(n, vector<int>(n, 0));
    int maxflow = 0;
    while (true) {
        vector<int> prev(n, -2);  // hkrati tudi visited array
        int bot = INF;            // bottleneck
        queue<triple> q;
        q.push({s, -1, INF});
        while (!q.empty()) {      // compute a possible path, add its bottleneck to the total flow
            int u = q.front().u, p = q.front().p, mini = q.front().m;  // while such path exists
            q.pop();

            if (prev[u] != -2) continue;
            prev[u] = p;

            if (u == t) { bot = mini; break; }

            for (int i = 0; i < n; ++i) {
                int available = capacity[u][i] - flow[u][i];
                if (available > 0) {
                    q.push({i, u, min(available, mini)});  // kumulativni minimum
                }
            }
        }

        if (prev[t] == -2) break;

        maxflow += bot;
        for (int u = t; u != s; u = prev[u]) {  // popravimo trenutni flow nazaj po poti
            flow[u][prev[u]] -= bot;
            flow[prev[u]][u] += bot;
        }
    }
    return maxflow;
}
