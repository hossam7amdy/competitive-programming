// https://leetcode.com/problems/separate-the-digits-in-an-array
#include<bits/stdc++.h>
using namespace std;

vector<int> separateDigits(vector<int>& nums) {
    vector<int> res;

    for(int i = 0; i < nums.size(); ++i)
        for(auto &digit : to_string(nums[i]))
            res.push_back(digit - '0');

    return res;
}

int main(){

    return 0;
}
