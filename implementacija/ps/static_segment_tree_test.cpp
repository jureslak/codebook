#include "static_segment_tree.h"

#include "gtest/gtest.h"

TEST(RangeQuery, RangeQuery) {
    RangeQuery rq({1, 2, 3, 4, -5, 6});
    EXPECT_EQ(1, rq.get(0, 1));
    EXPECT_EQ(1, rq.get(0, 2));
    EXPECT_EQ(1, rq.get(0, 3));
    EXPECT_EQ(1, rq.get(0, 4));
    EXPECT_EQ(-5, rq.get(0, 5));
    EXPECT_EQ(-5, rq.get(0, 6));
    EXPECT_EQ(3, rq.get(2, 4));
    rq.set(2, -7);
    EXPECT_EQ(-7, rq.get(0, 3));
    EXPECT_EQ(1, rq.get(0, 2));
    EXPECT_EQ(-7, rq.get(2, 6));
    EXPECT_EQ(-5, rq.get(3, 6));
}
