// https://leetcode.com/problems/optimal-partition-of-string/
#include<bits/stdc++.h>
using namespace std;

int partitionString(string s) {
    bool vis[26];
    memset(vis, 0, sizeof(vis));

    int count = 1;
    for(auto& ch : s){
        if(vis[ch - 'a']){
            ++count;
            memset(vis, 0, sizeof(vis));
        }
        vis[ch - 'a'] = 1;
    }

    return count;
}

int main(){

    return 0;
}
