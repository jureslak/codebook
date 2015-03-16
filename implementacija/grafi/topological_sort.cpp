#include "topological_sort.h"

vector<int> topological_sort(int n, int m, const int E[][2]) {
    vector<vector<int>> graf(n);
    vector<int> ingoing(n, 0);

    for (int i = 0; i < m; ++i) {
        int a = E[i][0], b = E[i][1];
        graf[a].push_back(b);
        ingoing[b]++;
    }

    queue<int> q;  // morda priority_queue, če je vrstni red pomemben
    for (int i = 0; i < n; ++i)
        if (ingoing[i] == 0)
            q.push(i);

    vector<int> res;
    while (!q.empty()) {
        int t = q.front();
        q.pop();

        res.push_back(t);

        for (int v : graf[t])
            if (--ingoing[v] == 0)
                q.push(v);
    }

    return res;  // če res.size() != n, ima graf cikle.
}
