#ifndef IMPLEMENTACIJA_PS_AVL_TREE_H_
#define IMPLEMENTACIJA_PS_AVL_TREE_H_

#include <algorithm>
#include <iostream>

using std::endl;
using std::max;
using std::ostream;

class AvlNode {
  public:
    AvlNode* left, *right;
    size_t height, size, count;
    int value;
    AvlNode(int v);
    ostream& print(ostream& os, int indent);
};

class AvlTree {
  public:
    AvlTree();
    int size() const;
    AvlNode* insert(int val);
    bool erase(int val);
    const AvlNode* get_nth(size_t index) const;
    const AvlNode* find(int value) const;
    friend std::ostream& operator<<(std::ostream& os, const AvlTree& tree);

  private:
    int size(const AvlNode* const& node) const;
    size_t height(const AvlNode* const& node) const;
    int getBalance(const AvlNode* const& node) const;
    void updateHeight(AvlNode* const& node);
    void rotateLeft(AvlNode*& node);
    void rotateRight(AvlNode*& node);
    void balance(AvlNode*& node);
    AvlNode* insert(int val, AvlNode*& node);
    bool erase(int val, AvlNode*& node);
    const AvlNode* get_nth(const AvlNode* const& node, size_t n) const;
    const AvlNode* find(const AvlNode* const& node, int value) const;

    AvlNode* root;
};

ostream& operator<<(ostream& os, const AvlTree& tree);

#endif  // IMPLEMENTACIJA_PS_AVL_TREE_H_
