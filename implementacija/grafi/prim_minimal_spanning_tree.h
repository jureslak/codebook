#ifndef IMPLEMENTACIJA_GRAFI_PRIM_MINIMAL_SPANNING_TREE_H_
#define IMPLEMENTACIJA_GRAFI_PRIM_MINIMAL_SPANNING_TREE_H_

#include <functional>
#include <queue>
#include <tuple>
#include <vector>

using std::greater;
using std::pair;
using std::priority_queue;
using std::tie;
using std::vector;

int prim_minimal_spanning_tree(const vector<vector<pair<int, int>>>& graf);

#endif  // IMPLEMENTACIJA_GRAFI_PRIM_MINIMAL_SPANNING_TREE_H_
