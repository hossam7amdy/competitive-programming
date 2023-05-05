// https://leetcode.com/problems/longest-palindromic-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static const int MAX = 1000 + 1;
    int memo[MAX][MAX];

    int dp(string& s, int st, int en){
        if(st == en)
            return 1;

        if(st > en)
            return 0;

        auto &ret = memo[st][en];
        if(ret != -1)
            return ret;

        ret = 0;
        if(s[st] == s[en])
            ret = 2 + dp(s, st + 1, en - 1);
        else{
            int skipLeft = dp(s, st + 1, en);
            int skipRight = dp(s, st, en - 1);
            ret =  max(skipLeft, skipRight);
        }

        return ret;
    }

public:
    int longestPalindromeSubseq(string s) {
        memset(memo, -1, sizeof(memo));
        return dp(s, 0, s.size() - 1);
    }
};

int main(){

    return 0;
}
