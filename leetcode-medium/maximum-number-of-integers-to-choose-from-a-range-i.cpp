// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/
#include<bits/stdc++.h>
using namespace std;

int maxCount(vector<int>& banned, int n, int maxSum) {
    unordered_set<int> hash = unordered_set(banned.begin(), banned.end());
    vector<int> good;

    for(int i = 1; i <= n; ++i)
        if(!hash.count(i))
            good.push_back(i);

    int curSum = 0;
    int res = 0;
    for(auto &num : good){
        curSum += num;
        if(curSum > maxSum)
            return res;
        ++res;
    }

    return res;
}

int main(){

    return 0;
}
