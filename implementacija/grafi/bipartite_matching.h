#ifndef IMPLEMENTACIJA_GRAFI_BIPARTITE_MATCHING_H_
#define IMPLEMENTACIJA_GRAFI_BIPARTITE_MATCHING_H_

#include <algorithm>
#include <vector>

using std::fill;
using std::vector;

int augmenting_path(const vector<vector<int>>& graf, int left);
void mark_vertices(const vector<vector<int>>& graf, vector<bool>& cover, int v);
int bipartite_matching(const vector<vector<int>>& graf, int left_num);
vector<int> minimal_cover(const vector<vector<int>>& graf, int left_num);

#endif  // IMPLEMENTACIJA_GRAFI_BIPARTITE_MATCHING_H_
