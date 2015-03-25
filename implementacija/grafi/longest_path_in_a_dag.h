#ifndef IMPLEMENTACIJA_GRAFI_LONGEST_PATH_IN_A_DAG_H_
#define IMPLEMENTACIJA_GRAFI_LONGEST_PATH_IN_A_DAG_H_

#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>

using std::vector;
using std::queue;
using std::pair;
using std::tie;
using std::max;

int longest_path_in_a_dag(const vector<vector<pair<int, int>>>& graf, int s, int t);

#endif  // IMPLEMENTACIJA_GRAFI_LONGEST_PATH_IN_A_DAG_H_
