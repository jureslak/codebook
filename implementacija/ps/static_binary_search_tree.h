#ifndef IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_
#define IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_

#include "static_binary_search_tree_util.h"

struct BST {
    int depth, n; // 1 << depth mora biti >= številu možnih elementov
    vector<int> tree;  // number of elements in the tree = tree[0]

    BST(int d) : depth(d), n(1 << d), tree(2*n, 0) {}

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
};
ostream& operator<<(ostream& os, const BST& t) {
    for (int i = 0; i <= t.depth; ++i) {
        os << string((1 << (t.depth - i)) - 1, ' ');
        for (int j = (1 << i) - 1; j < (1 << (i+1)) - 1; ++j) {
            os << t.tree[j] << string((1 << (t.depth - i + 1)) - 1, ' ');
        }
        os << '\n';
    }
    return os;
}
#endif  // IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_
