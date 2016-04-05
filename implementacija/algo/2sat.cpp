#include "2sat.h"

int var2node(int var, int n) {  // sprem. od $\pm 1$ do $\pm n$ spremeni v vozlišče od 0 do $2n-1$
    return (var > 0) ? var - 1 : -var - 1 + n;
}

namespace {
int dfscount;
vector<int> postorder;
vector<int> comp;  // comp[i] pove v kateri componenti je i. Componente so top. urejene.
vector<bool> visited;
}

void get_postorder(const vector<vector<int>>& G, int v) {  // izračuna čase odhodov iz vozlišč
    visited[v] = true;
    for (int u : G[v])
        if (!visited[u])
            get_postorder(G, u);
    postorder[dfscount--] = v;
}

void mark_comp(const vector<vector<int>>& G, int v, int scccount) {  // najde povezane komponente
    comp[v] = scccount;
    for (int u : G[v])
        if (comp[u] == -1)
            mark_comp(G, u, scccount);
}

vector<int> solve_2sat(const vector<pair<int, int>>& formula, int n) {
    vector<vector<int>> G(2*n), GR(2*n);
    int x, y;
    for (const auto& term : formula) {  // Imamo stavek x v y.
        tie(x, y) = term;  // Naredimo dva sklepa: -x => y, -y => x
        int tx = var2node(x, n), ty = var2node(y, n);
        int nx = var2node(-x, n), ny = var2node(-y, n);
        G[nx].push_back(ty); G[ny].push_back(tx);   // naredimo graf implikacij
        GR[ty].push_back(nx); GR[tx].push_back(ny);  // in obraten graf
    }

    dfscount = 2*n-1;
    postorder.resize(2*n);
    visited.assign(2*n, false);
    for (int i = 0; i < 2*n; ++i)
        if (!visited[i])
            get_postorder(G, i);

    comp.assign(2*n, -1);
    int scccount = 0;
    for (int v : postorder)
        if (comp[v] == -1)
            mark_comp(GR, v, scccount++);

    for (int i = 0; i < n; ++i) {
        if (comp[i] == comp[n+i])
            return vector<int>(n, -1);  // ali false
    }  // ce ne rabis resitve lahko das tukaj return true;

    vector<int> solution(n);
    for (int i = 0; i < n; ++i)
        solution[i] = comp[i] > comp[n+i];
    return solution;
}

bool evaluate(const vector<pair<int, int>>& formula, const vector<int>& values) {
    int x, y;  // izračuna vrednost formule pri danem naboru vrednosti spremenljivk
    for (const auto& p : formula) {  // pricakujemo da so v formuli stevilke od \pm 1 do \pm n
        tie(x, y) = p;               // in da imamo n vrednosti, ki so 0 ali 1
        bool vx = values[abs(x)-1] ^ (x < 0);
        bool vy = values[abs(y)-1] ^ (y < 0);
        if (!(vx || vy)) return false;
    }
    return true;
}
