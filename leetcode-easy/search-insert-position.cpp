// https://leetcode.com/problems/search-insert-position/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(logn)
    - Memory: O(1)
*/

int searchInsert(vector<int>& nums, int target) {
    if(nums.back() < target)
        return nums.size();
    return (lower_bound(nums.begin(), nums.end(), target) - nums.begin());
}

int main() {
    return 0;
}
