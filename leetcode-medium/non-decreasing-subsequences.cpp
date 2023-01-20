// https://leetcode.com/problems/non-decreasing-subsequences/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(2^n * n^2)
    - Space: O(2^n * n)
*/

class Solution {
    vector<int> cur;
    vector<int> nums;
    set<vector<int>> result;

    void backtrack(int idx){
        if(idx == nums.size())
            return;

        if(cur.size() > 1)
            result.insert(cur);

        for(int i = idx + 1; i < nums.size(); ++i){
            if(nums[i] >= nums[idx]){
                cur.push_back(nums[i]);

                backtrack(i);

                cur.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums_) {
        nums = nums_;
        nums.insert(nums.begin(), -100); // dummey

        backtrack(0);

        return vector<vector<int>>(result.begin(), result.end());
    }
};

int main(){

    return 0;
}
