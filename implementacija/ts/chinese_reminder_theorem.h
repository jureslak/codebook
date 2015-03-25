#ifndef IMPLEMENTACIJA_TS_CHINESE_REMINDER_THEOREM_H_
#define IMPLEMENTACIJA_TS_CHINESE_REMINDER_THEOREM_H_

#include "implementacija/ts/extended_gcd.h"

#include <iterator>
#include <tuple>
#include <utility>
#include <vector>

using std::pair;
using std::tie;
using std::vector;

int mul_inverse(int a, int m);
int chinese_reminder_theorem(const vector<pair<int, int>>& cong);

#endif  // IMPLEMENTACIJA_TS_CHINESE_REMINDER_THEOREM_H_
