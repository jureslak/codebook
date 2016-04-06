#include "knuth_morris_pratt.h"

#include "gtest/gtest.h"

TEST(KMP, FailureFunction) {
    vector<int> expected = {0, 0, 0, 0, 1, 2, 0 };
    vector<int> result = compute_failure_function("ABCDABD");
    EXPECT_EQ(expected, result);
}

TEST(KMP, Match) {
    int i;
    i = knuth_morris_pratt("ABCD", "BC");
    EXPECT_EQ(1, i);
    i = knuth_morris_pratt("AAAAAAAA", "AAA");
    EXPECT_EQ(0, i);
    i = knuth_morris_pratt("AAAAABAA", "AAB");
    EXPECT_EQ(3, i);
    i = knuth_morris_pratt("AAAAABAAC", "AAC");
    EXPECT_EQ(6, i);
    i = knuth_morris_pratt("AAAAABAAC", "C");
    EXPECT_EQ(8, i);
    i = knuth_morris_pratt("ABC ABCDAB ABCDABCDABDE", "ABCDABD");
    EXPECT_EQ(15, i);
    i = knuth_morris_pratt("ABC ABCDAB ABCDABCDABDE", "ABCDEABD");
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt("ABA", "BASDFASD");
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt("ABA", "BAB");
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt("ABA", "AA");
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt("ABA", "BB");
    EXPECT_EQ(-1, i);
}
TEST(KMP, MatchStart) {
    int i;
    string p = "ABC", s = "ABCABCABCABC";
    vector<int> ff = compute_failure_function(p);
    i = knuth_morris_pratt(s, p, ff, 0);
    EXPECT_EQ(0, i);
    i = knuth_morris_pratt(s, p, ff, 1);
    EXPECT_EQ(3, i);
    i = knuth_morris_pratt(s, p, ff, 2);
    EXPECT_EQ(3, i);
    i = knuth_morris_pratt(s, p, ff, 3);
    EXPECT_EQ(3, i);
    i = knuth_morris_pratt(s, p, ff, 4);
    EXPECT_EQ(6, i);
    i = knuth_morris_pratt(s, p, ff, 5);
    EXPECT_EQ(6, i);
    i = knuth_morris_pratt(s, p, ff, 6);
    EXPECT_EQ(6, i);
    i = knuth_morris_pratt(s, p, ff, 7);
    EXPECT_EQ(9, i);
    i = knuth_morris_pratt(s, p, ff, 8);
    EXPECT_EQ(9, i);
    i = knuth_morris_pratt(s, p, ff, 9);
    EXPECT_EQ(9, i);
    i = knuth_morris_pratt(s, p, ff, 10);
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt(s, p, ff, 11);
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt(s, p, ff, 12);
    EXPECT_EQ(-1, i);
    i = knuth_morris_pratt(s, p, ff, 120);
    EXPECT_EQ(-1, i);
}

TEST(KMP, FindAllOccurences) {
    string p = "ABA", s = "ABABABABA";
    vector<int> a = find_all_occurences(s, p);
    vector<int> expected = {0, 2, 4, 6};
    EXPECT_EQ(expected, a);
}

TEST(KMP, FindNonOverlapingOccurences) {
    string p = "ABA", s = "ABABABABA";
    vector<int> a = find_non_overlaping_occurences(s, p);
    vector<int> expected = {0, 4};
    EXPECT_EQ(expected, a);
}
TEST(KMP, MinimalPeriod) {
    EXPECT_EQ(1, minimal_period("A"));
    EXPECT_EQ(1, minimal_period("AA"));
    EXPECT_EQ(1, minimal_period("AAAAAAAAAAAA"));
    EXPECT_EQ(2, minimal_period("ABABABABABAB"));
    EXPECT_EQ(11, minimal_period("ABABABABABA"));
    EXPECT_EQ(3, minimal_period("ABCABCABC"));
    EXPECT_EQ(8, minimal_period("ABCABCAB"));
}
