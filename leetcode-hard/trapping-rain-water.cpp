#include <bits/stdc++.h>
using namespace std;

/*
# Statement
    Given an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
    EX. [0,1,0,2,1,0,1,3,2,1,2,1] => 6

#Intuition
    If we know the max height of the left and the right building then we can calculate how much water the current building can hold.

# Approach 1: Two pointers + maxHeap
    - left pointer to utilize the max building on the left side
    - maxHeap to store all the right side building sorted in ascending order
    - with each move calculate how many water can the current building can hold & update left and right pointers

# Complexity
    - Time complexity: O(nlogn)
    - Space complexity: O(n)
*/

int trap(const vector<int>& height) {
    int maxWater = 0;
    int leftMax = height[0];
    // use reverse sorted vector
    vector<pair<int,int>> maxHeap;

    for(int i = 1; i < (int)height.size(); ++i)
        maxHeap.push_back({height[i], i});

    sort(maxHeap.begin(), maxHeap.end());

    for(int i = 1; i < (int)height.size() - 1; ++i){
        while(i >= maxHeap.back().second)
            maxHeap.pop_back();

        int curVal = height[i];

        // update left and right max
        auto rightMax = maxHeap.back();
        leftMax = max(leftMax, curVal);

        // add if valid
        maxWater += max(min(leftMax, rightMax.first) - curVal, 0);
    }

    return maxWater;
}

int main(){
    cout << trap({0,1,0,2,1,0,1,3,2,1,2,1}) << "\n"; // 6
    cout << trap({4,2,0,3,2,5}) << "\n"; // 9
    cout << trap({0,1,2,3}) << "\n"; // 0
    cout << trap({3,2,1,0}) << "\n"; // 0
    cout << trap({3,2,1,0,1,2,3}) << "\n"; // 9
    cout << trap({0,1,2,3,3,2,1,0}) << "\n"; // 0

    return 0;
}
