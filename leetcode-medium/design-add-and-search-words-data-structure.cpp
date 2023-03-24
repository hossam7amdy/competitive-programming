// https://leetcode.com/problems/design-add-and-search-words-data-structure/
#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct TrieNode {
        static const int MAX_CHARS = 26;
        TrieNode* child[MAX_CHARS];
        bool isLeaf = false;
    };

    TrieNode* root {};

    bool backtrack(TrieNode* root, string& word, int idx){
        if(!root)
            return false;
        if(idx == word.size())
            return root->isLeaf;

        bool isFound = false;
        if(word[idx] != '.')
            return backtrack(root->child[word[idx] - 'a'], word, idx + 1);

        for(int i = 0; i < 26; ++i){
            if(root->child[i])
                isFound |= backtrack(root->child[i], word, idx + 1);
        }

        return isFound;
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        auto node = root;
        for(auto& ch : word){
            int idx = ch - 'a';
            if(!node->child[idx])
                node->child[idx] = new TrieNode();
            node = node->child[idx];
        }
        node->isLeaf = true;
    }

    bool search(string word) {
        return backtrack(root, word, 0);
    }
};

int main(){

    return 0;
}

