#include <bits/stdc++.h>
using namespace std;

/*
SOLUIONS:
    1-nested loop -> O(n^2) time & O(1) space = TLE
    2-hash set + count sort -> O(N) time & space
    3-sort -> O(nlogn) time & O(1) space
*/

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> visited;
    for(auto item : nums){
        if(visited.count(item)){
            return true;
        }else{
            visited.insert(item);
        }
    }
    return false;
}

bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    for(int i = 1; i < (int)nums.size(); ++i){
        if(nums[i - 1] == nums[i])
            return true;
    }
    return false;
}

int main(){


    return 0;
}
