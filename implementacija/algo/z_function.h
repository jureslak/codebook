#ifndef IMPLEMENTACIJA_ALGO_Z_FUNCTION_H_
#define IMPLEMENTACIJA_ALGO_Z_FUNCTION_H_

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::min;

vector<int> z_function(const string& s);
int match(const string& s, const string& p);
int minimal_period_zf(const string& s);

#endif  // IMPLEMENTACIJA_ALGO_Z_FUNCTION_H_
