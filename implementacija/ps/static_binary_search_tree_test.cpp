#include "static_binary_search_tree.h"

#include "gtest/gtest.h"

TEST(StaticBST, Works) {
    insert(0, 1);
    insert(1023, 1);
    EXPECT_EQ(0, get_kth(0));
    EXPECT_EQ(1023, get_kth(1));
    insert(1000, 5);
    EXPECT_EQ(1000, get_kth(1));
    remove(1000);
    remove(1000);
    remove(1000);
    remove(1000);
    EXPECT_EQ(1000, get_kth(1));
    remove(1000);
    insert(500, 1);
    insert(500, 1);
    EXPECT_EQ(0, get_kth(0));
    EXPECT_EQ(500, get_kth(1));
    EXPECT_EQ(500, get_kth(2));
    EXPECT_EQ(1023, get_kth(3));
}
