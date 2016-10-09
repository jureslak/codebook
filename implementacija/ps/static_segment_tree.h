#ifndef IMPLEMENTACIJA_PS_STATIC_SEGMENT_TREE_H_
#define IMPLEMENTACIJA_PS_STATIC_SEGMENT_TREE_H_

#include "static_segment_tree_util.h"

const int inf = 1e9;
struct RangeQuery {  // Change inf and min below to your operation and initial value
    int n;  // size of the tree
    vector<int> tree;  // 1-based
    RangeQuery(const vector<int>& a) :  // Constructs a queryable structure over you list
            n(1 << static_cast<int>(ceil(log2(a.size())))),
            tree(2*n, inf) {
        for (size_t i = 0; i < a.size(); ++i) tree[n+i] = a[i];
        for (int i = n - 1; i; --i) tree[i] = min(tree[2*i], tree[2*i+1]);
    }
    void set(int pos, int x) {
        for (int i = pos + n; i; i >>= 1) tree[i] = min(tree[i], x);
    }
    int get(int s, int e) const {  // [s, e) i.e. s <= i < e
        int res = inf;
        for (s += n, e += n; s < e; s >>= 1, e >>= 1) {
            if (s & 1) res = min(res, tree[s++]);
            if (e & 1) res = min(res, tree[--e]);
        }
        return res;
    }
};
ostream& operator<<(ostream& os, const RangeQuery& rq) {  // fancy print
    int depth = static_cast<int>(log2(rq.n));
    for (int i = 0; i <= depth; ++i) {
        os << string((1 << (depth - i)) - 1, ' ');
        for (int j = (1 << i); j < (1 << (i+1)); ++j) {
            os << rq.tree[j] << string((1 << (depth - i + 1)) - 1, ' ');
        }
        os << '\n';
    }
    return os;
}
#endif  // IMPLEMENTACIJA_PS_STATIC_SEGMENT_TREE_H_
