#ifndef IMPLEMENTACIJA_ALGO_MAXIMUM_SUBARRAY_H_
#define IMPLEMENTACIJA_ALGO_MAXIMUM_SUBARRAY_H_

#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using std::tuple;
using std::tie;
using std::pair;
using std::make_tuple;
using std::make_pair;
using std::max;
using std::vector;
using std::priority_queue;

int maximum_subarray(const vector<int>& a);
vector<int> maximum_subarray_extract(const vector<int>& a);
int maximum_subarray(const vector<int>& a, int k);

#endif  // IMPLEMENTACIJA_ALGO_MAXIMUM_SUBARRAY_H_
