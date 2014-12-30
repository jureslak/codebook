#ifndef IMPLEMENTACIJA_GRAFI_STRONGLY_CONNECTED_COMPONENTS_H_
#define IMPLEMENTACIJA_GRAFI_STRONGLY_CONNECTED_COMPONENTS_H_

#include <algorithm>
#include <map>
#include <stack>
#include <utility>
#include <vector>

using std::map;
using std::min;
using std::pair;
using std::stack;
using std::vector;

void strongly_connected_components(const vector<vector<pair<int, int>>>& G,
        vector<vector<int>>& comps, vector<map<int, int>>& dag);

#endif  // IMPLEMENTACIJA_GRAFI_STRONGLY_CONNECTED_COMPONENTS_H_
