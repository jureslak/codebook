#include "bipartite_matching.h"

namespace {
vector<int> match;
vector<bool> vis;
}

bool augmenting_path(const vector<vector<int>>& graf, int left) {
    if (vis[left]) return false;
    vis[left] = true;
    for (int right : graf[left]) {
        if (match[right] == -1 || augmenting_path(graf, match[right])) {
            match[right] = left;
            match[left] = right;
            return true;
        }
    }
    return false;
}

void mark_vertices(const vector<vector<int>>& graf, vector<bool>& cover, int v) {
    if (vis[v]) return;
    vis[v] = true;
    cover[v] = false;
    for (int r : graf[v]) {
        cover[r] = true;
        if (match[r] != -1)
            mark_vertices(graf, cover, match[r]);
    }
}

int bipartite_matching(const vector<vector<int>>& graf, int left_num) {
    int n = graf.size();
    match.assign(2*n, -1);
    int mcbm = 0;             // prvih left_num je v levem delu grafa
    for (int left = 0; left < left_num; ++left) {
        vis.assign(n, false);
        mcbm += augmenting_path(graf, left);
    }
    return mcbm;
}

vector<int> minimal_cover(const vector<vector<int>>& graf, int left_num) {
    bipartite_matching(graf, left_num);
    int n = graf.size();
    vis.assign(2*n, false);
    vector<bool> cover(n, false);
    fill(cover.begin(), cover.begin() + left_num, true);
    for (int left = 0; left < n; ++left)
        if (match[left] == -1)
            mark_vertices(graf, cover, left);

    vector<int> result;  // ni potrebno, lahko se uporablja kar cover
    for (int i = 0; i < n; ++i)
        if (cover[i])
            result.push_back(i);
    return result;
}
