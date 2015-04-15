#ifndef IMPLEMENTACIJA_PS_TRIE_H_
#define IMPLEMENTACIJA_PS_TRIE_H_

#include "trie_util.h"

struct Node {
    int words, total;  // koliko besed se konča tukaj, koliko besed je v poddrevesu
    Node* nodes[26];
    Node() : words(0), total(0) {
        for (int i = 0; i < 26; ++i) nodes[i] = nullptr;
    }
    void add(const string& word, size_t idx = 0) {
        if (idx == word.size()) { words++; return; }
        int p = word[idx]-'a';
        if (nodes[p] == nullptr) nodes[p] = new Node();
        total++;
        nodes[p]->add(word, idx+1);
    }
    void print(int n, string& prefix) {
        if (n == 0) return;
        for (int j = 0; j < words; ++j)
            printf("%s\n", prefix.c_str());

        for (int i = 0; i < 26; ++i) {
            if (nodes[i] != nullptr) {
                prefix.push_back('a'+i);
                nodes[i]->print(n-1, prefix);
                prefix.pop_back();
            }
        }
    }
    int longest_common_prefix_length() {  // najdaljši skupen prefix med besedami v drevesu
        int childc = 0;
        int maxl = 0;
        for (int i = 0; i < 26; ++i) {
            if (nodes[i] != nullptr) {
                childc++;
                maxl = max(maxl, nodes[i]->longest_common_prefix_length());
            }
        }
        if (maxl > 0) return maxl+1;  // ce je match v poddrevesu, imamo match+1
        return childc > 1 || (childc == 1 && words > 0) || (words > 1);
    }  // sicer imamo match ce sta dve isti ali imamo otroka in mi eno besedo ali dva otroka
    int common_prefix(const string& s, size_t x = 0) {  // koliko crk imata skupnih
        if (nodes[s[x]-'a'] == nullptr || x == s.size()) return x;
        return nodes[s[x]-'a']->common_prefix(s, x+1);
    }
    int size() { return total+words; }
    ~Node() {
        for (int i = 0; i < 26; ++i)
            delete nodes[i];
    }
};

#endif  // IMPLEMENTACIJA_PS_TRIE_H_
