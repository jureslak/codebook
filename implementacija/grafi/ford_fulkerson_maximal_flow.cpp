#include "ford_fulkerson_maximal_flow.h"

int dfs(int cur, int t, vector<bool>& visited, vector<vector<int>>& flow, int f = 20000) {
    visited[cur] = true;
    if (cur == t) return f;
    int n = flow.size();
    for (int y = 0; y < n; ++y) {
        if (flow[cur][y] > 0 && !visited[y]) {
            int df = dfs(y, t, visited, flow, min(f, flow[cur][y]));
            if (df > 0) {
                flow[cur][y] -= df;
                flow[y][cur] += df;
                return df;
            }
        }
    }
    return 0;
}

int ford_fulkerson_maximal_flow(const vector<vector<int>>& capacity, int s, int t) {
    vector<vector<int>> flow = capacity;
    int max_flow = 0, df;
    do {
        vector<bool> visited(flow.size(), false);
        df = dfs(s, t, visited, flow);
        max_flow += df;
    } while (df != 0);
    return max_flow;
}

