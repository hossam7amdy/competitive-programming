// https://leetcode.com/problems/maximum-difference-between-increasing-elements/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach: DP
    - SAME Idea as => 121.Best Time to Buy and Sell Stock

# Complexity
    - Time: O(n)
    - Memory: O(1)
*/

int maximumDifference(vector<int>& nums) {
    int maxDiff = 0;
    int minEle = nums.front();
    for(auto &num : nums){
        minEle = min(minEle, num);
        maxDiff = max(maxDiff, num - minEle);
    }

    return !maxDiff ? -1 : maxDiff;
}

int main() {
    return 0;
}
