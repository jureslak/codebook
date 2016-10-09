#include "all_pairs_widest_path.h"

vector<vector<int>> all_pairs_widest_path(const vector<vector<pair<int, int>>>& graf_) {
    auto graf = graf_;
    int n = graf.size();
    // Prepiši vse povezave v en velik container
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; i++) {
        sort(graf[i].begin(), graf[i].end(), [](const pair<int, int>& p, const pair<int, int>& q) {
                if (p.second == q.second) return p.first > q.first;
                return p.second > q.second; });
        for (const auto& p : graf[i]) {
            edges.push_back(make_tuple(p.second, p.first, i));  // w, v, u (reversed for sorting)
        }
    }
    sort(edges.begin(), edges.end(), greater<tuple<int, int, int>>());

    vector<vector<int>> result(n, vector<int>(n, 0));  // note: morda ull
    vector<bool> visited;
    queue<int> q;
    vector<int> vertex_degree;  // koliko edgev, ki vodijo iz mesta si ze dodal
    int u, v, w;

    // start in each vertex
    for (int i = 0; i < n; ++i) {
        visited.assign(n, false);  // Reset these
        vertex_degree.assign(n, 0);
        visited[i] = true;  // I am visited

        // add edges one by one from bigger to smaller weight
        for (auto e : edges) {
            tie(w, v, u) = e;
            vertex_degree[u]++;  // Oznacimo, da smo dodali dodatno cesto

            if (visited[u] && !visited[v]) {  // Ce smo iz ze dosezenega mesta prisli do novega
                visited[v] = true;  // Dodaj se med visited in dodaj svojo sirino v result
                result[i][v] = w;
                if (vertex_degree[v] > 0) {  // Ce je treba: flood fill
                    q.push(v);
                    while (!q.empty()) {
                        int cur = q.front();
                        q.pop();
                        for (int k = 0; k < vertex_degree[cur]; ++k) {
                            auto sosed = graf[cur][k].first;  // samo prvih toliko je obiskanih
                            if (!visited[sosed]) {            // zato smo jih prej sortirali
                                visited[sosed] = true;
                                result[i][sosed] = w;
                                q.push(sosed);
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}
