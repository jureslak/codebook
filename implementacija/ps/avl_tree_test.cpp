#include "avl_tree.h"

#include "gtest/gtest.h"

TEST(AvlTree, Insert) {
    AvlTree<int> t;
    ASSERT_EQ(0, t.size());
    t.insert(-2);
    ASSERT_EQ(1, t.size());
    t.insert(-1);
    ASSERT_EQ(2, t.size());
    ASSERT_EQ(-2, t.get_nth(0)->value);
    ASSERT_EQ(-1, t.get_nth(1)->value);
    for (int i = 0; i < 100; ++i) {
        t.insert(i);
        ASSERT_EQ(i, t.get_nth(i+2)->value);
    }
    for (int i = -12; i < 300; ++i) {
        t.insert(-i);
        if (i > 3)
            ASSERT_EQ(-i, t.get_nth(0)->value);
    }
    ASSERT_EQ(414, t.size());
    ASSERT_EQ(2, t.find(0)->count);
    ASSERT_EQ(nullptr, t.find(1234));
    ASSERT_EQ(nullptr, t.get_nth(-1));
    ASSERT_EQ(nullptr, t.get_nth(7737723));
}

TEST(AvlTree, Delete) {
    AvlTree<int> t;
    for (int i = 0; i < 500; i++) t.insert(i % 100);
    ASSERT_EQ(t.size(), 500);
    ASSERT_EQ(true, t.erase(0));
    ASSERT_EQ(499, t.size());
    ASSERT_EQ(true, t.erase(0));
    ASSERT_EQ(true, t.erase(0));
    ASSERT_EQ(true, t.erase(0));
    ASSERT_EQ(true, t.erase(0));
    ASSERT_EQ(495, t.size());
    ASSERT_EQ(false, t.erase(0));
    ASSERT_EQ(495, t.size());
}
