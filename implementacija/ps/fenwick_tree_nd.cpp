#include "fenwick_tree_nd.h"

typedef vector<vector<vector<int>>> vvvi;

int sum(int x, int y, int z, const vvvi& tree) {  // [0,0,0 - x,y,z] vključno
    int result = 0;
    for (int i = x; i >= 0; i = (i & (i+1)) - 1)
        for (int j = y; j >= 0; j = (j & (j+1)) - 1)
            for (int k = z; k >= 0; k = (k & (k+1)) - 1)
                result += tree[i][j][k];
    return result;
}

void inc(int x, int y, int z, int delta, vvvi& tree) {  // povečaj na koordinatah, 0 based
    int n = tree.size();  // lahko so tudi različni n-ji za posamezno dimenzijo
    for (int i = x; i < n; i |= i+1)
        for (int j = y; j < n; j |= j+1)
            for (int k = z; k < n; k |= k+1)
                tree[i][j][k] += delta;
}

int subsum(int x1, int y1, int z1,
           int x2, int y2, int z2, const vvvi& tree) {  // vsota na [x1,y1,z1 - x2,y2,z2], vključno
    x1--; y1--; z1--;
    return sum(x2, y2, z2, tree) -
           sum(x1, y2, z2, tree) -
           sum(x2, y1, z2, tree) -  // pravilo vključitev in izključitev
           sum(x2, y2, z1, tree) +
           sum(x1, y1, z2, tree) +
           sum(x1, y2, z1, tree) +
           sum(x2, y1, z1, tree) -
           sum(x1, y1, z1, tree);
}
