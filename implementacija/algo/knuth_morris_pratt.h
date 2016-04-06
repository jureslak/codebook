#ifndef IMPLEMENTACIJA_ALGO_KNUTH_MORRIS_PRATT_H_
#define IMPLEMENTACIJA_ALGO_KNUTH_MORRIS_PRATT_H_

#include <vector>
#include <string>

using std::vector;
using std::string;

vector<int> compute_failure_function(const string& p);
int knuth_morris_pratt(const string& s, const string& p, const vector<int>& ff, int start);
int knuth_morris_pratt(const string& s, const string& p);
vector<int> find_all_occurences(const string& s, const string & p);
vector<int> find_non_overlaping_occurences(const string& s, const string & p);
int minimal_period(const string& s);


#endif  // IMPLEMENTACIJA_ALGO_KNUTH_MORRIS_PRATT_H_
