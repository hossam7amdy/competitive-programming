// https://leetcode.com/problems/concatenated-words/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: Hashing + DFS

#Complexity
    - Time: O(N * L^3)
    - Space: O(N * L)
*/

class Solution {
    unordered_set<string> hashSet;

    bool isValid(string word, int idx){
        if(idx == word.size())
            return true;

        string subWord = "";
        for(int i = idx; i < word.size(); ++i){
            subWord += word[i];
            if(subWord == word)
                return false;

            if(hashSet.count(subWord) && isValid(word, i + 1))
                return true;
        }

        return false;
    }

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        hashSet = unordered_set(words.begin(), words.end());
        vector<string> result;

        for(auto &word : words){
            if(isValid(word, 0))
                result.push_back(word);
        }

        return result;
    }
};

int main(){


    return 0;
}
