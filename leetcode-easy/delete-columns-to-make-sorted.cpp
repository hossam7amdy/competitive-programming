// https://leetcode.com/problems/delete-columns-to-make-sorted

#include<bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string>& strs) {
    int res = 0;
    for(int i = 0; i < strs[0].size(); ++i){
        for(int j = 1; j < strs.size(); ++j){
            if(strs[j-1][i] > strs[j][i]){
                ++res;
                break;
            }
        }
    }

    return res;
}

int main(){

    return 0;
}
