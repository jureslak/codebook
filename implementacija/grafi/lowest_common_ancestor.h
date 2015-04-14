#ifndef IMPLEMENTACIJA_GRAFI_LOWEST_COMMON_ANCESTOR_H_
#define IMPLEMENTACIJA_GRAFI_LOWEST_COMMON_ANCESTOR_H_

#include <vector>

using std::vector;
using std::size_t;
using std::swap;

vector<vector<int>> preprocess(const vector<int>& parent);
vector<int> levels(const vector<int>& parent);
int find_lca(const vector<int>& parent, int u, int v,
             const vector<vector<int>>& P, const vector<int>& L);

#endif  // IMPLEMENTACIJA_GRAFI_LOWEST_COMMON_ANCESTOR_H_
