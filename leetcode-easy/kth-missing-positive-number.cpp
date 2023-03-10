// https://leetcode.com/problems/kth-missing-positive-number/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Space: O(1)
*/

int findKthPositive(vector<int>& arr, int k) {
    int missing;
    int expected = 1;
    for(int i = 0; i < arr.size();){
        if(arr[i] == expected)
            ++i;
        else{
            --k;
            missing = expected;
        }
        if(!k)
            return missing;
        ++expected;
    }

    return k + arr.back();
}

int main(){

    return 0;
}
