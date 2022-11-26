#include <bits/stdc++.h>
using namespace std;

/*
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

    Solution: in a Stack A close one. It must match open one.
        - Time: O(n)
        - Space: O(1)
*/

class Solution {
    bool isOpen(char ch){
    return ch == '(' || ch == '{' || ch == '[';
}

public:
    bool isValid(string s) {
        map<char,char> mp;
        mp[']'] = '[';
        mp['}'] = '{';
        mp[')'] = '(';

        stack<char> st;
        for(auto ch : s){
            if(isOpen(ch))
                st.push(ch);
            else{
                if(st.empty() || mp[ch] != st.top())
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

int main(){

    return 0;
}
