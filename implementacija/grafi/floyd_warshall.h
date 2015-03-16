#ifndef IMPLEMENTACIJA_GRAFI_FLOYD_WARSHALL_H_
#define IMPLEMENTACIJA_GRAFI_FLOYD_WARSHALL_H_

#include <vector>
#include <map>
#include <limits>

using std::map;
using std::vector;
using std::numeric_limits;

vector<vector<int>> floyd_warshall(int n, int m, const int E[][3]);

#endif  // IMPLEMENTACIJA_GRAFI_FLOYD_WARSHALL_H_
