#ifndef IMPLEMENTACIJA_GRAFI_ALL_PAIRS_WIDEST_PATH_H_
#define IMPLEMENTACIJA_GRAFI_ALL_PAIRS_WIDEST_PATH_H_

#include <algorithm>
#include <functional>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include <iostream>

using std::greater;
using std::make_tuple;
using std::pair;
using std::queue;
using std::sort;
using std::tie;
using std::tuple;
using std::vector;

vector<vector<int>> all_pairs_widest_path(const vector<vector<pair<int, int>>>& graf);

#endif  // IMPLEMENTACIJA_GRAFI_ALL_PAIRS_WIDEST_PATH_H_
