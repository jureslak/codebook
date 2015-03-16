#ifndef IMPLEMENTACIJA_GRAFI_DIJKSTRA_SQUARE_H_
#define IMPLEMENTACIJA_GRAFI_DIJKSTRA_SQUARE_H_

#include <algorithm>
#include <limits>
#include <tuple>
#include <vector>

using std::numeric_limits;
using std::pair;
using std::reverse;
using std::tie;
using std::vector;

vector<int> dijkstra_square(const vector<vector<pair<int, int>>>& graf, int s, int t);

#endif  // IMPLEMENTACIJA_GRAFI_DIJKSTRA_SQUARE_H_
