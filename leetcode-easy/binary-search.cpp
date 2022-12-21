#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int st = 0, en = nums.size() - 1;

    if(nums[st] == target)
        return st;

    while(st <= en){
        int mid = st + (en - st) / 2;

        if(target == nums[mid])
            return mid;

        if(target > nums[mid])
            st = mid + 1;
        else
            en = mid - 1;
    }

    return -1;
}


int main(){

    return 0;
}
