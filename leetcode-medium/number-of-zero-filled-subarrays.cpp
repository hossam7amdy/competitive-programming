// https://leetcode.com/problems/number-of-zero-filled-subarrays/
#include<bits/stdc++.h>
using namespace std;

long long zeroFilledSubarray(vector<int>& nums) {
    long long res = 0, numSubarray = 0;
    for(auto& num : nums){
        if(num == 0)
            ++numSubarray;
        else
            numSubarray = 0;

        res += numSubarray;
    }

    return res;
}

int main(){

    return 0;
}

