#include "avl_tree.h"

//  class AvlNode {
//    public:
//      AvlNode* left, *right;
//      size_t height, size, count;
//      int value;
AvlNode::AvlNode(int v) : left(nullptr), right(nullptr), height(1), size(1), count(1), value(v) {}
ostream& AvlNode::print(ostream& os, int indent = 0) {
    if (right != nullptr) right->print(os, indent+2);
    for (int i = 0; i < indent; ++i) os << ' ';  // or use string(indent, ' ')
    os << value << endl;
    if (left != nullptr) left->print(os, indent+2);
    return os;
}
//  };

//  class AvlTree {
//    public:
AvlTree::AvlTree() : root(nullptr) {}
int AvlTree::size() const {
    return size(root);
}
AvlNode* AvlTree::insert(int val) {
    return insert(val, root);
}
bool AvlTree::erase(int val) {
    return erase(val, root);
}
const AvlNode* AvlTree::get_nth(size_t index) const {
    return get_nth(root, index);
}
const AvlNode* AvlTree::find(int value) const {
    return find(root, value);
}
//  friend ostream& operator<<(ostream& os, const AvlTree& tree);

//    private:
int AvlTree::size(const AvlNode* const& node) const {
    if (node == nullptr) return 0;
    else return node->size;
}
size_t AvlTree::height(const AvlNode* const& node) const {
    if (node == nullptr) return 0;
    return node->height;
}
int AvlTree::getBalance(const AvlNode* const& node) const {
    return height(node->left) - height(node->right);
}
void AvlTree::updateHeight(AvlNode* const& node) {
    node->height = max(height(node->left), height(node->right)) + 1;
}
void AvlTree::rotateLeft(AvlNode*& node) {
    AvlNode* R = node->right;
    node->size -= size(R->right) + R->count; R->size += size(node->left) + node->count;
    node->right = R->left; R->left = node; node = R;
    updateHeight(node->left); updateHeight(node);
}
void AvlTree::rotateRight(AvlNode*& node) {
    AvlNode* L = node->left;
    node->size -= size(L->left) + L->count; L->size += size(node->right) + node->count;
    node->left = L->right; L->right = node; node = L;
    updateHeight(node->right); updateHeight(node);
}
void AvlTree::balance(AvlNode*& node) {
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
AvlNode* AvlTree::insert(int val, AvlNode*& node) {
    if (node == nullptr) return node = new AvlNode(val);
    node->size++;
    AvlNode* return_node = node;
    if (val < node->value) return_node = insert(val, node->left);
    else if (node->value == val) node->count++;
    else if (node->value < val) return_node = insert(val, node->right);
    balance(node);
    return return_node;
}
bool AvlTree::erase(int val, AvlNode*& node) {
    if (node == nullptr) return 0;
    if (val < node->value) {
        if (erase(val, node->left)) {
            node->size--;
            return 1;
        }
    } else if (node->value < val) {
        if (erase(val, node->right)) {
            node->size--;
            return 1;
        }
    } else if (node->value == val && node->count > 0) {
        node->count--;
        node->size--;
        return 1;
    }
    return 0;
}
const AvlNode* AvlTree::get_nth(const AvlNode* const& node, size_t n) const {
    size_t left_size = size(node->left);
    if (n < left_size) return get_nth(node->left, n);
    else if (n < left_size + node->count) return node;
    else if (n < node->size) return get_nth(node->right, n - left_size - node->count);
    else return nullptr;
}
const AvlNode* AvlTree::find(const AvlNode* const& node, int value) const {
    if (node == nullptr) return nullptr;
    if (value < node->value) return find(node->left, value);
    else if (value == node->value) return node;
    else return find(node->right, value);
}

//      AvlNode* root;
//  };

ostream& operator<<(ostream& os, const AvlTree& tree) {
    if (tree.root == nullptr) os << "Tree empty";
    else tree.root->print(os);
    return os;
}
