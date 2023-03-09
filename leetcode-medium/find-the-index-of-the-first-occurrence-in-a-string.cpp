// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Memory: O(1)
*/

class Solution {
    bool isSame(vector<int> counter, string& s1, string& s2, int i2){
        for(auto& count : counter)
            if(count != 0)
                return false;

        for(int i1 = 0; i1 < s1.size(); ++i1, ++i2){
            if(s1[i1] != s2[i2])
                return false;
        }
        return true;
    }
public:
    int strStr(string haystack, string needle) {
        int needleSize = needle.size();
        int haystackSize = haystack.size();
        if(needleSize > haystackSize)
            return -1;

        vector<int> counter(26, 0);
        for(int i = 0; i < needleSize; ++i){
            char ch1 = needle[i], ch2 = haystack[i];
            counter[ch1 - 'a']++;
            counter[ch2 - 'a']--;
        }

        if(isSame(counter, needle, haystack, 0))
            return 0;

        for(int i = needleSize; i < haystackSize; ++i){
            char ch1 = haystack[i], ch2 = haystack[i - needleSize];
            counter[ch1 - 'a']--;
            counter[ch2 - 'a']++;

            if(isSame(counter, needle, haystack, i - needleSize + 1))
                return i - needleSize + 1;
        }

        return -1;
    }
};

int main() {
    return 0;
}
