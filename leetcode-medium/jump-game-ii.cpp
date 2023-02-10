// https://leetcode.com/problems/jump-game-ii/
#include<bits/stdc++.h>
using namespace std;

// O(n^2)
class Solution {
    int dp(const vector<int> &nums, int i, vector<int> &memo){
        if(i == nums.size() - 1)
            return 0;

        auto &ret = memo[i];
        if(ret != -1)
            return ret;

        ret = nums.size();
        for(int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
            ret = min(ret, 1 + dp(nums, i+j, memo));

        return ret;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, -1);

        return dp(nums, 0, memo);
    }
};

int main(){

    return 0;
}
