#include<bits/stdc++.h>
using namespace std;

class Solution {
    string str;
    vector<string> ans;

    void backtrack(int n, int open, int close){
        if(str.size() == 2 * n){
            ans.push_back(str);
            return;
        }

        if(open < n){
            ++open;
            str.push_back('(');

            backtrack(n, open, close);

            str.pop_back();
            --open;
        }

        if(close < open){
            ++close;
            str.push_back(')');

            backtrack(n, open, close);

            str.pop_back();
            --close;
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        backtrack(n,0,0);
        return ans;
    }
};

int main(){

    return 0;
}
