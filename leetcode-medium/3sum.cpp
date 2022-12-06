#include <bits/stdc++.h>
using namespace std;

/*
# Statement
    Return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k,
    and nums[i] + nums[j] + nums[k] == 0.
    EX. [-1,0,1,2,-1,-4] => [[-1,-1,2],[-1,0,1]]

#Intuition
    - If we fixed a number it became find two sum that equal to FIXED: (-target)
    - If found then we have one answer
    Notice: - one target can have more than one solution!
            - be careful there will be duplicates!

# Approach 1: sort + two pointers
    - sort input nums for fast lookups
    - for each num mark as target
    - and create tow pointers `st` & `en` such that `nums[st] + nums[en] == -target`

# Complexity
    - Time complexity: O(n^2)
    - Space complexity: O(1)
*/

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    int sz = (int)nums.size();

    for(int i = 0; i < sz; ++i){
        if(i && nums[i] == nums[i - 1]) // prevent duplicates
            continue;
        if(nums[i] > 0) // no more solutions
            break;

            int target = -nums[i];
            int st = i + 1, en = sz - 1;

            while(st < en){
                int curSum = nums[st] + nums[en];

                if(curSum < target)
                    ++st;
                else if(curSum > target)
                    --en;
                else{
                    result.push_back({nums[i],nums[st],nums[en]});
                    ++st;

                    // prevent duplicates
                    while(nums[st] == nums[st - 1] && st < en) ++st;
                }
            }
        }

    return result;
}

int main(){

    return 0;
}
