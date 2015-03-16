#ifndef IMPLEMENTACIJA_GRAFI_BELLMAN_FORD_H_
#define IMPLEMENTACIJA_GRAFI_BELLMAN_FORD_H_

#include <limits>
#include <tuple>
#include <vector>

using std::numeric_limits;
using std::pair;
using std::tie;
using std::vector;

vector<int> bellman_ford(const vector<vector<pair<int, int>>>& graf, int s);

#endif  // IMPLEMENTACIJA_GRAFI_BELLMAN_FORD_H_
