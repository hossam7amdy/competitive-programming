// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char ch){
        return vowels.count(ch);
    }

public:
    int maxVowels(string s, int k) {
        int res = 0;
        for(int i = 0; i < k; ++i)
            res += isVowel(s[i]);

        int count = res;
        for(int i = k; i < s.size(); ++i){
            char in = s[i];
            char out = s[i - k];

            count += isVowel(in);
            count -= isVowel(out);

            res = max(res, count);
        }

        return res;
    }
};

int main(){

    return 0;
}
