#include <bits/stdc++.h>
using namespace std;

/*
    Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
    EX. [100,4,200,1,3,2] => 4

    Approach 1: Sorting
        - when sorted we can easily split the sequence into sub-consecutive sequences
        - maximize among all sub-sequences
        - COMPLEXITY
            - Time: O(nlogn)
            - Space: O(1)

    Approach 2: Hash Set
        - copy nums into hash set for fast lookup O(1)
        - for each number if begin of a sequence start counting
        - maximize among all sub-sequences
        - COMPLEXITY
            - Time: O(n)
            - Space: O(n)
*/

int longestConsecutive_(vector<int>& nums) {
    int bestSeq = 0;
    if(!(int)nums.size())
        return bestSeq;

    sort(nums.begin(), nums.end());
    nums.push_back(1e9 + 1); // trick: force compare last sequence

    int curSeq = 1;
    for(int i = 1; i < (int)nums.size(); ++i){
        if(nums[i] == nums[i-1]) continue;

        if(nums[i] - nums[i-1] == 1){
            ++curSeq;
            continue;
        }

        bestSeq = max(bestSeq, curSeq);
        curSeq = 1;
    }

    return bestSeq;
}

int longestConsecutive(const vector<int>& nums) {
    unordered_set<int> numSet = unordered_set<int>(nums.begin(), nums.end());

    int bestSeq = 0;
    for(const int &num : nums){
        if(!numSet.count(num - 1)){
            int curSeq = 1;
            for(int edge = num; numSet.count(edge + 1); ++edge)
                ++curSeq;

            bestSeq = max(bestSeq, curSeq);
        }
    }

    return bestSeq;
}

int main(){

    cout << longestConsecutive_({0,3,7,2,5,8,4,6,0,1}) << "\n";
    cout << longestConsecutive_({100,4,200,1,3,2}) << "\n";
    cout << longestConsecutive_({0,-1,1}) << "\n";

    return 0;
}
