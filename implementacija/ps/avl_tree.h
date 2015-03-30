#ifndef IMPLEMENTACIJA_PS_AVL_TREE_H_
#define IMPLEMENTACIJA_PS_AVL_TREE_H_

#include "avl_tree_util.h"

template<typename T>
class AvlNode {
  public:
    AvlNode<T>* left, *right;
    size_t height, size, count;
    T value;
    AvlNode(const T& v) : left(nullptr), right(nullptr), height(1), size(1), count(1), value(v) {}
    ostream& print(ostream& os, int indent = 0) {
        if (right != nullptr) right->print(os, indent+2);
        for (int i = 0; i < indent; ++i) os << ' ';  // or use string(indent, ' ')
        os << value << endl;
        if (left != nullptr) left->print(os, indent+2);
        return os;
    }
};

template<typename T>
class AvlTree {
  public:
    AvlTree() : root(nullptr) {}
    int size() const {
        return size(root);
    }
    AvlNode<T>* insert(const T& val) {
        return insert(val, root);
    }
    bool erase(const T& val) {
        return erase(val, root);
    }
    const AvlNode<T>* get_nth(size_t index) const {
        return get_nth(root, index);
    }
    const AvlNode<T>* find(const T& value) const {
        return find(root, value);
    }
    template<typename U>
    friend ostream& operator<<(ostream& os, const AvlTree<U>& tree);

  private:
    int size(const AvlNode<T>* const& node) const {
        if (node == nullptr) return 0;
        else return node->size;
    }
    size_t height(const AvlNode<T>* const& node) const {
        if (node == nullptr) return 0;
        return node->height;
    }
    int getBalance(const AvlNode<T>* const& node) const {
        return height(node->left) - height(node->right);
    }
    void updateHeight(AvlNode<T>* const& node) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }
    void rotateLeft(AvlNode<T>*& node) {
        AvlNode<T>* R = node->right;
        node->size -= size(R->right) + R->count; R->size += size(node->left) + node->count;
        node->right = R->left; R->left = node; node = R;
        updateHeight(node->left); updateHeight(node);
    }
    void rotateRight(AvlNode<T>*& node) {
        AvlNode<T>* L = node->left;
        node->size -= size(L->left) + L->count; L->size += size(node->right) + node->count;
        node->left = L->right; L->right = node; node = L;
        updateHeight(node->right); updateHeight(node);
    }
    void balance(AvlNode<T>*& node) {
        int b = getBalance(node);
        if (b == 2) {
            if (getBalance(node->left) == -1) rotateLeft(node->left);
            rotateRight(node);
        } else if (b == -2) {
            if (getBalance(node->right) == 1) rotateRight(node->right);
            rotateLeft(node);
        } else {
            updateHeight(node);
        }
    }
    AvlNode<T>* insert(const T& val, AvlNode<T>*& node) {
        if (node == nullptr) return node = new AvlNode<T>(val);
        node->size++;
        AvlNode<T>* return_node = node;
        if (val < node->value) return_node = insert(val, node->left);
        else if (node->value == val) node->count++;
        else if (node->value < val) return_node = insert(val, node->right);
        balance(node);
        return return_node;
    }
    bool erase(const T& val, AvlNode<T>*& node) {
        if (node == nullptr) return false;
        if (val < node->value) {
            if (erase(val, node->left)) {
                node->size--;
                return true;
            }
        } else if (node->value < val) {
            if (erase(val, node->right)) {
                node->size--;
                return true;
            }
        } else if (node->value == val && node->count > 0) {
            node->count--;
            node->size--;
            return true;
        }
        return false;
    }
    const AvlNode<T>* get_nth(const AvlNode<T>* const& node, size_t n) const {
        size_t left_size = size(node->left);
        if (n < left_size) return get_nth(node->left, n);
        else if (n < left_size + node->count) return node;
        else if (n < node->size) return get_nth(node->right, n - left_size - node->count);
        else return nullptr;
    }
    const AvlNode<T>* find(const AvlNode<T>* const& node, const T& value) const {
        if (node == nullptr) return nullptr;
        if (value < node->value) return find(node->left, value);
        else if (value == node->value) return node;
        else return find(node->right, value);
    }

    AvlNode<T>* root;
};

template<typename T>
ostream& operator<<(ostream& os, const AvlTree<T>& tree) {
    if (tree.root == nullptr) os << "Tree empty";
    else tree.root->print(os);
    return os;
}
#endif  // IMPLEMENTACIJA_PS_AVL_TREE_H_
