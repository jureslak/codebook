#ifndef IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_
#define IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;

void insert(int idx, int val);
int get_kth(int k);
bool remove(int idx);
int size();
void print();

#endif  // IMPLEMENTACIJA_PS_STATIC_BINARY_SEARCH_TREE_H_
