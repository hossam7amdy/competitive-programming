#include <bits/stdc++.h>
using namespace std;

/*
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

    SOLUTIONS:
    1- nested loop: for each num find its complement -> O(n^2)
    2- sort + BS: for each num BS for its complement -> O(nlogn) & O(n) space
    3- hash map: store values in a hash map & find complement in O(1) -> O(n) time & space
*/

vector<int> twoSum_1(const vector<int>& nums, int target) { // O(n^2)
    for(int i = 0; i < (int)nums.size(); ++i){
        for(int j = 0; j < (int)nums.size(); ++j){
            if(i == j) continue;
            if(nums[i] + nums[j] == target)
                return {i,j};
        }
    }

    return {0,0};
}

vector<int> twoSum_2(const vector<int> &nums, int target) { // O(nlogn) time & O(n) space
    vector<int> SortedNums = nums;
    sort(SortedNums.begin(), SortedNums.end());

    int st = 0, en = (int)SortedNums.size() - 1;
    while(st < en){
        if(SortedNums[st] + SortedNums[en] > target)
            --en;
        else if(SortedNums[st] + SortedNums[en] < target)
            ++st;
        else
            break;
    }

    int idx1=-1,idx2;
    for(int i = 0; i < (int)nums.size(); ++i){
        if(nums[i] == SortedNums[st] && idx1 == -1)
            idx1 = i;
        if(nums[i] == SortedNums[en] && idx1 != i)
            idx2 = i;
    }

    return {idx1,idx2};
}

vector<int> twoSum_3(const vector<int>& nums, int target) { // O(n) time & space
    unordered_map<int,int> mp;

    for(int i = 0; i < (int)nums.size(); ++i){
        int complement = target - nums[i];
        if(mp.count(complement))
            return {mp[complement], i};
        else
            mp.insert({nums[i], i});
    }

    return {0,0};
}

int main() {
    vector<int> res = twoSum_3({3,3}, 6);
    for(auto num : res)
        cout << num << " ";

    return 0;
}
