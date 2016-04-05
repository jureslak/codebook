#ifndef IMPLEMENTACIJA_ALGO_2SAT_H_
#define IMPLEMENTACIJA_ALGO_2SAT_H_

#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using std::tie;
using std::pair;
using std::make_pair;
using std::vector;

int var2node(int var, int n);
vector<int> solve_2sat(const vector<pair<int, int>>& formula, int n);
bool evaluate(const vector<pair<int, int>>& formula, const vector<int>& values);

#endif  // IMPLEMENTACIJA_ALGO_2SAT_H_
