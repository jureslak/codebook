#ifndef IMPLEMENTACIJA_PS_FENWICK_TREE_ND_H_
#define IMPLEMENTACIJA_PS_FENWICK_TREE_ND_H_

#include <vector>

using std::vector;

int sum(int x, int y, int z, const vector<vector<vector<int>>>& tree);
void inc(int x, int y, int z, int delta, vector<vector<vector<int>>>& tree);
int subsum(int x1, int y1, int z1, int x2, int y2, int z2,
           const vector<vector<vector<int>>>& tree);

#endif  // IMPLEMENTACIJA_PS_FENWICK_TREE_ND_H_
