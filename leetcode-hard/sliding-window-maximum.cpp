#include<bits/stdc++.h>
using namespace std;

/*
# Approach: maxHeap (sliding window)
    - keep max values until get out of range

# Complexity
    - Time: O(nlogn)
    - Space: O(n)
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    priority_queue<pair<int,int>> window;

    for(int r = 0; r < nums.size(); ++r){
        window.push({nums[r],r});

        int l = r - k + 1;
        while(window.top().second < l) // eliminate out of range values
            window.pop();

        if(window.size() >= k)
            res.push_back(window.top().first);
    }

    return res;
}

int main(){

    return 0;
}
