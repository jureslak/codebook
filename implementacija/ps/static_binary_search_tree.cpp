#include "static_binary_search_tree.h"

namespace {
int depth = 10;  // depth of the tree
int n = 1 << 10;  // number of different elements stored
vector<int> tree(2*n);  // numer of elements in the tree = tree[0]
}

void insert(int idx, int val = 1) {
    int i = n - 1 + idx;
    while (i > 0) {
        tree[i] += val;
        i--;
        i >>= 1;
    }
    tree[0] += val;
}

int get_kth(int k) {
    int i = 0;
    while (i < n - 1) {
        int lc = tree[2*i+1];
        if (lc <= k) {
            i = 2*i + 2;
            k -= lc;
        } else {
            i = 2*i + 1;
        }
    }
    return i - n + 1;
}

bool remove(int idx) {
    if (tree[n-1 + idx] <= 0) return false;
    insert(idx, -1);
    return true;
}

void print() {
    for (int i = 0; i <= depth; ++i) {
        cout << string((1 << (depth - i)) - 1, ' ');
        for (int j = (1 << i) - 1; j < (1 << (i+1)) - 1; ++j) {
            cout << tree[j] << string((1 << (depth - i + 1)) - 1, ' ');
        }
        cout << '\n';
    }
}
