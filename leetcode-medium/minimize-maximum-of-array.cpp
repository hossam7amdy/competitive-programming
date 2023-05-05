// https://leetcode.com/problems/minimize-maximum-of-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    typedef long long ll;

    bool check(vector<int>& nums, ll target){
        ll prev = nums[0];
        if(prev > target) return false;
        for(int i = 1; i < nums.size(); ++i){
            ll diff = target - prev;
            prev = nums[i] - diff;
            if(prev > target) return false;
        }

        return true;
    }

public:
    int minimizeArrayValue(vector<int>& nums) {
        int res = *max_element(nums.begin(),nums.end());
        int st = 0, en = res;

        while(st <= en){
            int mid = st + (en - st) / 2;

            if(check(nums, mid))
                en = mid - 1, res = mid;
            else
                st = mid + 1;
        }

        return res;
    }
};

int main(){

    return 0;
}
