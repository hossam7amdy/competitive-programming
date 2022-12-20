#include<bits/stdc++.h>
using namespace std;

/*
#Approach: Binary Search
    - split the array and decide witch direction is best

#Complexity
    - Time: O(logn)
    - Space: O(1)
*/

int findMin(const vector<int>& nums) {
    int st = 0, en = (int)nums.size() - 1;

    while(st < en){
        int mid = st + (en - st) / 2;

        if(mid && nums[mid-1] >= nums[mid] && nums[mid] <= nums[mid+1])
            return nums[mid]; // found [2,1,3]

        if(nums[mid] < nums[en])
            en = mid - 1;
        else
            st = mid + 1;
    }

    return nums[st];
}


int main(){
    // even
    cout << findMin({1,2,3,4}) << "\n";
    cout << findMin({4,1,2,3}) << "\n";
    cout << findMin({3,4,1,2}) << "\n";
    cout << findMin({2,3,4,1}) << "\n";

    // odd
    cout << findMin({1,2,3,4,5}) << "\n";
    cout << findMin({5,1,2,3,4}) << "\n";
    cout << findMin({4,5,1,2,3}) << "\n";
    cout << findMin({3,4,5,1,2}) << "\n";
    cout << findMin({2,3,4,5,1}) << "\n";

    return 0;
}
