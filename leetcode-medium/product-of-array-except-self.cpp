#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array nums, return an array answer such that answer[i]
    is equal to the product of all the elements of nums except nums[i].
    Ex. [1,2,3,4] => [24,12,8,6]

    SOLUTION:
    Suffix Sum Algorithm:
        - create prefix & suffix array
        - calculate prefix & suffix product (e.g., prefix[i] *= prefix[i-1], suffix[i] *= suffix[i+1])
        - compute result as answer[i] = prefix[i-1] * suffix[i+1]

    >> Complexity: O(n)
*/

vector<int> productExceptSelf(vector<int>& nums) {
    int n = (int)nums.size();
    vector<int> prefix(n), suffix(n);

    prefix[0] = nums[0];
    for(int i = 1; i < n; ++i)
        prefix[i] = prefix[i-1] * nums[i];

    suffix[n-1] = nums[n-1];
    for(int i = n - 2; i >= 0; --i)
        suffix[i] = nums[i] * suffix[i + 1];

    nums[0] = suffix[1];
    nums[n-1] = prefix[n-2];
    for(int i = 1; i < n-1; ++i)
        nums[i] = prefix[i-1] * suffix[i+1];

    return nums;
}

int main() {

    return 0;
}
