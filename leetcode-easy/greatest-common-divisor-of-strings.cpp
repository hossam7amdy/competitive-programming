// https://leetcode.com/problems/greatest-common-divisor-of-strings/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: Greedy

#Complexity
    - Time: O(min(m,n) *(m+n))
    - Space: O(1)
*/

class Solution {
    bool isGood(string &str, string &gcd){
        int strSz = str.size(), gcdSz = gcd.size();
        if(strSz % gcdSz != 0)
            return false;

        for(int i = 0; i < strSz; i += gcdSz){
            for(int g = 0, s = i; g < gcdSz; ++g, ++s)
                if(str[s] != gcd[g])
                    return false;
        }

        return true;
    }

public:
    string gcdOfStrings(string str1, string str2) {
        int sz1 = str1.size(), sz2 = str2.size();
        if(sz1 > sz2)
            return gcdOfStrings(str2, str1);

        string gcd = str1;
        for(int i = 0; i < sz1; ++i){
            int gcdSz = gcd.size();

            if(isGood(str1, gcd) && isGood(str2, gcd))
                return gcd;

            gcd.pop_back();
        }

        return "";
    }
};

int main(){

    return 0;
}
