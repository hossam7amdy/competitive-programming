// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int sLen = s.size();
        int pLen = p.size();
        if(pLen > sLen)
            return res;

        vector<int> freqs(26);
        for(int i = 0; i < pLen; ++i){
            freqs[p[i] - 'a']++;
            freqs[s[i] - 'a']--;
        }
        if(isPermutation(freqs))
            res.push_back(0);

        for(int i = pLen; i < sLen; ++i){
            freqs[s[i] - 'a']--;
            freqs[s[i - pLen] - 'a']++;

            if(isPermutation(freqs))
                res.push_back(i - pLen + 1);
        }

        return res;
    }

private:
    bool isPermutation(vector<int> &freqs){
        for(auto &freq : freqs)
            if(freq != 0)
                return false;
        return true;
    }
};

int main(){

    return 0;
}
