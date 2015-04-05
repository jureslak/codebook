#include "segment_tree.h"

#include "gtest/gtest.h"

TEST(SegmentTree, Simple) {
    int start = -3;
    int end = 10;
    SimpleNode* root = new SimpleNode();
    EXPECT_EQ(0, root->cnt);
    root->insert(start, end, 1);
    EXPECT_EQ(1, root->cnt);
    root->insert(start, end, 1);
    EXPECT_EQ(2, root->cnt);
    root->insert(start, end, 1);
    root->insert(start, end, 7);
    EXPECT_EQ(4, root->cnt);
    EXPECT_EQ(1, root->pop_kth(start, end, 3));
    EXPECT_EQ(1, root->pop_kth(start, end, 2));
    EXPECT_EQ(1, root->pop_kth(start, end, 1));
    EXPECT_EQ(1, root->cnt);
    root->insert(start, end, 7);
    root->insert(start, end, 8);
    root->insert(start, end, 9);
    EXPECT_EQ(7, root->pop_kth(start, end, 2));
    EXPECT_EQ(8, root->pop_kth(start, end, 2));
    EXPECT_EQ(7, root->pop_kth(start, end, 1));
    EXPECT_EQ(9, root->pop_kth(start, end, 1));
    EXPECT_EQ(0, root->cnt);
}

TEST(SegmentTree, Complete) {
    int start = -100;
    int end = 100;
    Node* root = new Node(start, end);
    root->insert(1, 1, 1);
    root->insert(2, 2, 1);
    root->insert(3, 3, 1);
    root->insert(4, 4, 1);
    EXPECT_EQ(4, root->count(-10, 10));
    EXPECT_EQ(4, root->count(1, 4));
    EXPECT_EQ(3, root->count(1, 3));
    EXPECT_EQ(3, root->count(2, 4));
    EXPECT_EQ(2, root->count(1, 2));
    EXPECT_EQ(2, root->count(2, 3));
    EXPECT_EQ(2, root->count(3, 4));
    EXPECT_EQ(1, root->count(1, 1));
    EXPECT_EQ(1, root->count(-99, 1));
    EXPECT_EQ(1, root->count(2, 2));
    EXPECT_EQ(1, root->count(3, 3));
    EXPECT_EQ(1, root->count(4, 4));
    EXPECT_EQ(1, root->count(4, 99));
    EXPECT_EQ(1, root->get_kth(0));
    EXPECT_EQ(2, root->get_kth(1));
    EXPECT_EQ(3, root->get_kth(2));
    EXPECT_EQ(4, root->get_kth(3));
    root->insert(start, end, 2);
    EXPECT_EQ(start, root->get_kth(0));
    EXPECT_EQ(start, root->get_kth(1));
    EXPECT_EQ(start+1, root->get_kth(2));
    EXPECT_EQ(start+2, root->get_kth(4));
    EXPECT_EQ(3, root->count(4, 4));
    EXPECT_EQ(6, root->count(1, 2));
    root->insert(1, 2, 1);
    EXPECT_EQ(8, root->count(1, 2));
    EXPECT_EQ(10, root->count(2, 4));
    root->insert(start, end, -1);
    EXPECT_EQ(7, root->count(2, 4));
    root->insert(start, end, -1);
    EXPECT_EQ(4, root->count(2, 4));
    EXPECT_EQ(4, root->count(2, 4));
    EXPECT_EQ(6, root->count(start, end));
    root->insert(-1, 5, 1);
    EXPECT_EQ(-1, root->get_kth(0));
    EXPECT_EQ(0, root->get_kth(1));
    EXPECT_EQ(1, root->get_kth(2));
    EXPECT_EQ(1, root->get_kth(3));
    EXPECT_EQ(1, root->get_kth(4));
    EXPECT_EQ(2, root->get_kth(5));
    ASSERT_EQ(2, root->get_kth(6));
    EXPECT_EQ(2, root->get_kth(7));
    EXPECT_EQ(3, root->get_kth(8));
    EXPECT_EQ(3, root->get_kth(9));
    EXPECT_EQ(4, root->get_kth(10));
    EXPECT_EQ(4, root->get_kth(11));
    EXPECT_EQ(5, root->get_kth(12));
}
