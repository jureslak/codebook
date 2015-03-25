#include "topological_sort.h"

vector<int> topological_sort(const vector<vector<int>>& graf) {
    int n = graf.size();
    vector<int> ingoing(n, 0);
    for (int i = 0; i < n; ++i)
        for (const auto& u : graf[i])
            ingoing[u]++;

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
