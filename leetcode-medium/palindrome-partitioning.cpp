// https://leetcode.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    string s;
    vector<string> curPartition;
    vector<vector<string>> result;

    bool isPalindrome(string str){
        int l = 0, r = str.size() - 1;
        while(l < r)
            if(str[l++] != str[r--])
                return false;
        return true;
    }

    void backtrack(int idx){
        if(idx == s.size()){
            result.push_back(curPartition);
            return;
        }

        string pal = "";
        for(int i = idx; i < s.size(); ++i){
            pal += s[i];
            if(isPalindrome(pal)){
                curPartition.push_back(pal);

                backtrack(i + 1);

                curPartition.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s_) {
        s = s_;
        backtrack(0);
        return result;
    }
};

int main(){

    return 0;
}
