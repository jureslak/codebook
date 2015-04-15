#include "trie.h"

#include "gtest/gtest.h"

TEST(Trie, Works) {
    Node* root = new Node();
    EXPECT_EQ(0, root->size());
    root->add("jure");
    EXPECT_EQ(1, root->size());
    root->add("jureslak");
    EXPECT_EQ(4+1, root->longest_common_prefix_length());
    EXPECT_EQ(3, root->common_prefix("jurq"));
    root->add("jureslak");
    EXPECT_EQ(8+1, root->longest_common_prefix_length());
    EXPECT_EQ(3, root->common_prefix("jurq"));
    EXPECT_EQ(4, root->common_prefix("jure"));
    EXPECT_EQ(7, root->common_prefix("juresla"));
    EXPECT_EQ(8, root->common_prefix("jureslakk"));
    root->add("a");
    root->add("aa");
    root->add("aaa");
    root->add("aaaaa");
    root->add("aaaaaaaaabaa");
    root->add("aaaaaaaaabbb");
    root->add("aaab");
    EXPECT_EQ(6, root->common_prefix("aaaaaa"));
    EXPECT_EQ(10+1, root->longest_common_prefix_length());
}
