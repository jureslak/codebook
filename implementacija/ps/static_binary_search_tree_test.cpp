#include "static_binary_search_tree.h"

#include "gtest/gtest.h"

TEST(StaticBST, Works) {
    BST tree(10);
    tree.insert(0, 1);
    tree.insert(1023, 1);
    EXPECT_EQ(0, tree.get_kth(0));
    EXPECT_EQ(1023, tree.get_kth(1));
    tree.insert(1000, 5);
    EXPECT_EQ(1000, tree.get_kth(1));
    tree.remove(1000);
    tree.remove(1000);
    tree.remove(1000);
    tree.remove(1000);
    EXPECT_EQ(1000, tree.get_kth(1));
    tree.remove(1000);
    tree.insert(500, 1);
    tree.insert(500, 1);
    EXPECT_EQ(0, tree.get_kth(0));
    EXPECT_EQ(500, tree.get_kth(1));
    EXPECT_EQ(500, tree.get_kth(2));
    EXPECT_EQ(1023, tree.get_kth(3));
}
