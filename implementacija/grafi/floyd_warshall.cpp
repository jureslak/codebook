#include "floyd_warshall.h"

vector<vector<int>> floyd_warshall(int n, int m, const int E[][3]) {
    int INF = numeric_limits<int>::max();
    vector<vector<int>> d(n, vector<int>(n, INF));
    // vector<vector<int>> next(n, vector<int>(n, -1));  // da dobimo pot
    for (int i = 0; i < m; ++i) {
        int u = E[i][0], v = E[i][1], c = E[i][2];
        d[u][v] = c;
        // next[u][v] = v
    }

    for (int i = 0; i < n; ++i)
        d[i][i] = 0;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (d[i][k] != INF && d[k][j] != INF && d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
                    // next[i][j] = next[i][k];
    return d;  // ce je kateri izmed d[i][i] < 0, ima graf negativen cikel
}
