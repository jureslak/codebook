#ifndef IMPLEMENTACIJA_PS_SEGMENT_TREE_H_
#define IMPLEMENTACIJA_PS_SEGMENT_TREE_H_

#include "segment_tree_util.h"

struct Node {  // static division points, [l, r] intervals
    int l, m, r;
    Node* left, *right;
    int here_count, total_count;
    Node(int ll, int rr) : l(ll), m((ll+rr) / 2), r(rr),
                           left(nullptr), right(nullptr), here_count(0), total_count(0) {}
    int insert(int f, int t, int inc = 1) {  // insert inc elemnts into [f, t]. use for removal too
        if (f <= l && r <= t) {
            here_count += inc;
            int lb = max(l, f), rb = min(r, t);
            int inserted = (rb - lb + 1) * inc;
            total_count += inserted;
            return inserted;
        }
        int inserted = 0;
        if (f <= m) {
            if (left == nullptr) left = new Node(l, m);
            inserted += left->insert(f, t, inc);
        }
        if (m + 1 <= t) {
            if (right == nullptr) right = new Node(m + 1, r);
            inserted += right->insert(f, t, inc);
        }
        total_count += inserted;

        if (left != nullptr && right != nullptr) {  // move full levels up (speedup, ne rabiš)
            int child_here_count = min(left->here_count, right->here_count);
            left->here_count -= child_here_count;
            right->here_count -= child_here_count;
            here_count += child_here_count;
            left->total_count -= (m - l + 1) * child_here_count;
            right->total_count -= (r - m) * child_here_count;
        }  // end speed up
        return inserted;
    }

    int count(int f, int t) {  // count on interval [f, t]
        if (f <= l && r <= t) return total_count;
        int sum = 0, lb = max(l, f), rb = min(r, t);
        if (f <= m && left != nullptr) sum += left->count(f, t);
        if (m + 1 <= t && right != nullptr) sum += right->count(f, t);
        return sum + (rb - lb + 1) * here_count;
    }

    int get_kth(int k, int parent_count = 0) {  // zero based
        int above_count = here_count + parent_count;
        int lc = above_count * (m - l + 1) + get_cnt(left);
        if (k < lc) {
            if (left == nullptr) return l + k/above_count;
            return left->get_kth(k, above_count);
        } else {
            k -= lc;
            if (right == nullptr) return m + 1 + k/above_count;
            return right->get_kth(k, above_count);
        }
    }

    void print(int l, int r) {
        printf("[%d, %d]: here: %d, total: %d\n", l, r, here_count, total_count);
        if (left) left->print(l, m);
        if (right) right->print(m+1, r);
    }

  private:
    int get_cnt(Node* left) {
        return (left == nullptr) ? 0 : left->total_count;
    }
};

// poenostavitev, ce ne rabimo intervalov
struct SimpleNode {  // static division points
    SimpleNode* left, *right;
    int cnt;
    SimpleNode() : left(nullptr), right(nullptr), cnt(0) {}
    void insert(int l, int r, int val) {
        if (l == r) { cnt++; return; }
        int mid = (l + r) / 2;  // watch overflow
        if (val <= mid) {
            if (left == nullptr) left = new SimpleNode();
            left->insert(l, mid, val);
        } else {
            if (right == nullptr) right = new SimpleNode();
            right->insert(mid + 1, r, val);
        }
        cnt++;
    }

    int pop_kth(int l, int r, int k) {  // one based
        if (l == r) { cnt--; return l; }
        int mid = (l + r) / 2;
        if (k <= get_cnt(left)) {
            cnt--;
            return left->pop_kth(l, mid, k);
        } else {
            k -= get_cnt(left);
            cnt--;
            return right->pop_kth(mid + 1, r, k);
        }
    }

  private:
    int get_cnt(SimpleNode* x) {
        if (x == nullptr) return 0;
        return x->cnt;
    }
};
#endif  // IMPLEMENTACIJA_PS_SEGMENT_TREE_H_
