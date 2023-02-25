// https://leetcode.com/problems/single-element-in-a-sorted-array/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(logn)
    - Memory: O(1)
*/

int singleNonDuplicate(vector<int>& nums) {
    int st = 0, en = (int)nums.size() - 1;

    while(st < en){
        int mid = st + (en - st) / 2;

        if(nums[mid] == nums[mid-1]){
            int nMid = mid - 2;
            if(st <= nMid && (nMid - st + 1) % 2 == 1)
                en = mid - 2;
            else
                st = mid + 1;
        }else if(nums[mid] == nums[mid+1]){
            int nMid = mid + 2;
            if(nMid <= en && (en - nMid + 1) % 2 == 1)
                st = mid + 2;
            else
                en = mid - 1;
        }else
            return nums[mid];

    }

    return nums[st];
}

int main() {
    return 0;
}
