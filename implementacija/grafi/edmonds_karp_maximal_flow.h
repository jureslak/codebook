#ifndef IMPLEMENTACIJA_GRAFI_EDMONDS_KARP_MAXIMAL_FLOW_H_
#define IMPLEMENTACIJA_GRAFI_EDMONDS_KARP_MAXIMAL_FLOW_H_

#include <algorithm>
#include <limits>
#include <queue>
#include <vector>
#include <tuple>

using std::min;
using std::numeric_limits;
using std::queue;
using std::vector;
using std::tie;
using std::tuple;
using std::make_tuple;

int edmonds_karp_maximal_flow(const vector<vector<int>>& capacity, int s, int t);

#endif  // IMPLEMENTACIJA_GRAFI_EDMONDS_KARP_MAXIMAL_FLOW_H_
