#include "fenwick_tree.h"

namespace {
const int MAX_INDEX = 16;
vector<int> tree(MAX_INDEX+1, 0);  // global tree, 1 based!!
}

void update(int idx, int val) {  // increments idx for value
    while (idx <= MAX_INDEX) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int read(int idx) {  // read sum of [1, x], read(0) == 0, duh.
    int sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int readSingle(int idx) {  // read a single value, readSingle(x) == read(x)-read(x-1)
    int sum = tree[idx];
    if (idx > 0) {
        int z = idx - (idx & -idx);
        idx--;
        while (idx != z) {
            sum -= tree[idx];
            idx -= (idx & -idx);
        }
    }
    return sum;
}
