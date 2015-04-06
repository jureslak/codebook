#include "minimal_rotation.h"

#include "gtest/gtest.h"

TEST(MinimalRotaton, Works) {
    string a = "deafgaa";
    EXPECT_EQ(5, minimal_rotation(a));
    a = "d";
    EXPECT_EQ(0, minimal_rotation(a));
    a = "abcde0kas";
    EXPECT_EQ(5, minimal_rotation(a));
    a = "a0sdjs24r";
    EXPECT_EQ(1, minimal_rotation(a));
    a = "";
    EXPECT_EQ(0, minimal_rotation(a));
    a = "aaaabaaaaa";
    EXPECT_EQ(5, minimal_rotation(a));
}
