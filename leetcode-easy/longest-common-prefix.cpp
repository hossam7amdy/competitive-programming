#include<bits/stdc++.h>
using namespace std;

/*
#Approach: vertical scanning

#Complexity
    - Time: O(n * len)
    - Space: O(1)
*/

string longestCommonPrefix(vector<string>& strs) {
    string res = "";

    int sz = 200 + 1;
    for(auto str : strs) sz = min(sz,(int)str.size());

    for(int i = 0; i < sz; ++i){
        for(int j = 1; j < strs.size(); ++j){
            if(strs[j][i] != strs[j - 1][i])
                return res;
        }
        res += strs[0][i];
    }

    return res;
}


int main() {

    return 0;
}
