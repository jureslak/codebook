#include "longest_palindrome.h"

#include "gtest/gtest.h"

#include <tuple>

using std::tie;

TEST(Palindrome, Works) {
    string s;
    int f, t;
    s = "ssdfghjk";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(2, t);

    s = "sdfghjkk";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(6, f);
    EXPECT_EQ(8, t);

    s = "j";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(1, t);

    s = "";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(0, t);

    s = "aa";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(2, t);

    s = "babcbabcbaccba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(1, f);
    EXPECT_EQ(10, t);

    s = "abaaba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(6, t);

    s = "abababa";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(7, t);

    s = "abcbabcbabcba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(13, t);

    s = "forgeeksskeegfor";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(3, f);
    EXPECT_EQ(13, t);

    s = "caba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(1, f);
    EXPECT_EQ(4, t);

    s = "abacdfgdcaba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(3, t);

    s = "abacdfgdcabba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(9, f);
    EXPECT_EQ(13, t);

    s = "abacdedcaba";
    tie(f, t) = find_longest_palindrome(s);
    EXPECT_EQ(0, f);
    EXPECT_EQ(11, t);
}
