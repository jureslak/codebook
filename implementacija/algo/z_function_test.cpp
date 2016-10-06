#include "z_function.h"

#include "gtest/gtest.h"

TEST(ZFunction, Value) {
    vector<int> expected = {0, 4, 3, 2, 1};
    EXPECT_EQ(expected, z_function("aaaaa"));
    expected = {0, 2, 1, 0, 2, 1, 0};
    EXPECT_EQ(expected, z_function("aaabaab"));
    expected = {0, 0, 1, 0, 3, 0, 1};
    EXPECT_EQ(expected, z_function("abacaba"));
}

TEST(ZFunction, Match) {
    int i;
    i = match("ABCD", "BC");
    EXPECT_EQ(1, i);
    i = match("AAAAAAAA", "AAA");
    EXPECT_EQ(0, i);
    i = match("AAAAABAA", "AAB");
    EXPECT_EQ(3, i);
    i = match("AAAAABAAC", "AAC");
    EXPECT_EQ(6, i);
    i = match("AAAAABAAC", "C");
    EXPECT_EQ(8, i);
    i = match("ABC ABCDAB ABCDABCDABDE", "ABCDABD");
    EXPECT_EQ(15, i);
    i = match("ABC ABCDAB ABCDABCDABDE", "ABCDEABD");
    EXPECT_EQ(-1, i);
    i = match("ABA", "BASDFASD");
    EXPECT_EQ(-1, i);
    i = match("ABA", "BAB");
    EXPECT_EQ(-1, i);
    i = match("ABA", "AA");
    EXPECT_EQ(-1, i);
    i = match("ABA", "BB");
    EXPECT_EQ(-1, i);
}
TEST(ZFunction, MinimalPeriod) {
    EXPECT_EQ(1, minimal_period_zf("A"));
    EXPECT_EQ(1, minimal_period_zf("AA"));
    EXPECT_EQ(1, minimal_period_zf("AAAAAAAAAAAA"));
    EXPECT_EQ(2, minimal_period_zf("ABABABABABAB"));
    EXPECT_EQ(11, minimal_period_zf("ABABABABABA"));
    EXPECT_EQ(3, minimal_period_zf("ABCABCABC"));
    EXPECT_EQ(8, minimal_period_zf("ABCABCAB"));
}
