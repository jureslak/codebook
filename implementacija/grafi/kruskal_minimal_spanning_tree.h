#ifndef IMPLEMENTACIJA_GRAFI_KRUSKAL_MINIMAL_SPANNING_TREE_H_
#define IMPLEMENTACIJA_GRAFI_KRUSKAL_MINIMAL_SPANNING_TREE_H_

#include <algorithm>
#include <vector>
#include <tuple>

using std::sort;
using std::vector;
using std::tuple;
using std::tie;
using std::get;

int find(int x);
bool unija(int x, int y);
int kruskal_minimal_spanning_tree(int n, int m, int E[][3]);

#endif  // IMPLEMENTACIJA_GRAFI_KRUSKAL_MINIMAL_SPANNING_TREE_H_
