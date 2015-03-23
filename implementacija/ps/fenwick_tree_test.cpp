#include "fenwick_tree.h"

#include "gtest/gtest.h"

TEST(FenwickTest, FenwickTest) {
    for (int i = 1; i <= 16; ++i) {
        ASSERT_EQ(0, readSingle(i));
        ASSERT_EQ(0, read(i));
    }
    update(1, 3);
    ASSERT_EQ(3, read(1));
    update(2, 2);
    ASSERT_EQ(3, read(1));
    ASSERT_EQ(5, read(2));
    ASSERT_EQ(5, read(16));
    update(16, -5);
    ASSERT_EQ(0, read(16));
    ASSERT_EQ(5, read(15));
    ASSERT_EQ(3, read(1));
}
