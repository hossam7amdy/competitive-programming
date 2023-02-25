// https://leetcode.com/problems/minimize-deviation-in-array/
#include<bits/stdc++.h>
using namespace std;

int minimumDeviation(vector<int>& nums) {
    int minVal = 1e9;
    priority_queue<int> maxHeap;

    for(auto &num : nums){
        if(num % 2 == 0){
            maxHeap.push(num);
            minVal = min(minVal, num);
        }else{
            maxHeap.push(2 * num);
            minVal = min(minVal, 2 * num);
        }
    }

    int res = 1e9;
    while(maxHeap.top() % 2 == 0){
        int mx = maxHeap.top();
        maxHeap.pop();
        res = min(res, mx - minVal);
        int nNum = mx / 2;
        maxHeap.push(nNum);
        minVal = min(minVal, nNum);
    }

    return min(res, maxHeap.top() - minVal);
}

int main() {

    return 0;
}
