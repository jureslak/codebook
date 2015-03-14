#ifndef IMPLEMENTACIJA_GRAFI_DIJKSTRA_H_
#define IMPLEMENTACIJA_GRAFI_DIJKSTRA_H_

#include <functional>
#include <queue>
#include <tuple>
#include <vector>

using std::greater;
using std::pair;
using std::priority_queue;
using std::tie;
using std::vector;

int dijkstra(const vector<vector<pair<int, int>>>& graf, int s, int v);

#endif  // IMPLEMENTACIJA_GRAFI_DIJKSTRA_H_
