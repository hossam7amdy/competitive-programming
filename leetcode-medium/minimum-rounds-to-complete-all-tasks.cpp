// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

#include<bits/stdc++.h>
using namespace std;

int minimumRounds(vector<int>& tasks) {
    unordered_map<int,int> mp;
    for(auto task : tasks) mp[task]++;

    int res = 0;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        int curTasks = it->second;
        if(curTasks == 1){
            return -1;
        }

        while(curTasks % 3 != 0){
            curTasks -= 2;
            ++res;
        }
        res += curTasks / 3;
    }

    return res;
}

int main(){

    return 0;
}
