// https://leetcode.com/problems/removing-stars-from-a-string/
#include<bits/stdc++.h>
using namespace std;

string removeStars(string s) {
    string res = "";
    for(auto& ch : s){
        if(ch == '*')
            res.pop_back();
        else
            res.push_back(ch);
    }

    return res;
}

int main(){

    return 0;
}
