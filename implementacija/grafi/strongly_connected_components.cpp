#include "strongly_connected_components.h"

namespace {
vector<int> low;
vector<int> dfs_num;
stack<int> S;
vector<int> component;   // maps vertex to its component
}

void strongly_connected_components_internal(int u, const vector<vector<pair<int, int>>>& graf,
        vector<vector<int>>& comps) {
    static int dfs_num_counter = 1;
    low[u] = dfs_num[u] = dfs_num_counter++;
    S.push(u);

    for (const auto& v : graf[u]) {
        if (dfs_num[v.first] == 0)  // not visited yet
            strongly_connected_components_internal(v.first, graf, comps);
        if (dfs_num[v.first] != -1)  // not popped yet
            low[u] = min(low[u], low[v.first]);
    }

    if (low[u] == dfs_num[u]) {  // extract the component
        int cnum = comps.size();
        comps.push_back({});  // start new component
        int w;
        do {
            w = S.top(); S.pop();
            comps.back().push_back(w);
            component[w] = cnum;
            dfs_num[w] = -1;  // mark popped
        } while (w != u);
    }
}

void strongly_connected_components(const vector<vector<pair<int, int>>>& graf,
        vector<vector<int>>& comps, vector<map<int, int>>& dag) {
    int n = graf.size();
    low.assign(n, 0);
    dfs_num.assign(n, 0);
    component.assign(n, -1);

    for (int i = 0; i < n; ++i)
        if (dfs_num[i] == 0)
            strongly_connected_components_internal(i, graf, comps);

    dag.resize(comps.size());  // zgradimo kvocientni graf, teza povezave je vsota tez
    for (int u = 0; u < n; ++u) {
        for (const auto& v : graf[u]) {
            if (component[u] != component[v.first]) {
                dag[component[u]][component[v.first]] += v.second;  // ali max, kar zahteva naloga
            }
        }
    }
}
