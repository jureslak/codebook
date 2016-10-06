#ifndef IMPLEMENTACIJA_GRAFI_FORD_FULKERSON_MAXIMAL_FLOW_H_
#define IMPLEMENTACIJA_GRAFI_FORD_FULKERSON_MAXIMAL_FLOW_H_

#include <algorithm>
#include <vector>

using std::min;
using std::vector;

int ford_fulkerson_maximal_flow(const vector<vector<int>>& capacity, int s, int t);

#endif  // IMPLEMENTACIJA_GRAFI_FORD_FULKERSON_MAXIMAL_FLOW_H_
