// https://leetcode.com/problems/shuffle-the-array/
#include<bits/stdc++.h>
using namespace std;

public:
vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> res(2*n);
    int idx = 0;

    for(int i = 0, j = n; i < n; ++i, ++j){
        res[idx++] = nums[i];
        res[idx++] = nums[j];
    }

    return res;
}

int main(){

    return 0;
}
