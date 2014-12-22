#ifndef IMPLEMENTACIJA_GRAFI_ARTICULATION_POINTS_AND_BRIDGES_H_
#define IMPLEMENTACIJA_GRAFI_ARTICULATION_POINTS_AND_BRIDGES_H_

#include <algorithm>
#include <vector>

using std::min;
using std::pair;
using std::vector;

void articulation_points_and_bridges(int n, int m, const int E[][2],
        vector<int>& articulation_points, vector<pair<int, int>>& bridges);

#endif  // IMPLEMENTACIJA_GRAFI_ARTICULATION_POINTS_AND_BRIDGES_H_
