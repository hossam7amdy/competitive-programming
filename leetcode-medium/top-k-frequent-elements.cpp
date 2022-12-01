#include<bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL);

/*
    Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
    Ex. Input: [1,1,1,2,2,3] k = 2 -> Output [1,2]

    SOLUTIONS:
    - sorting: sort and count how many time an element appears => O(nlogn) time
    - hash map + max heap: count sort + k largest element -> O(n) time & space
*/

vector<int> topKFrequent(vector<int> nums, int k) {
    sort(nums.begin(), nums.end());

    vector<int> result;
    vector<pair<int,int>> freqs;

    int times = 1;
    nums.push_back(1e8); // trick: push last element
    for(int i = 1; i < (int)nums.size(); ++i){
        if(nums[i] == nums[i-1])
            ++times;
        else{
            freqs.push_back({times, nums[i-1]});
            times = 1;
        }
    }

    sort(freqs.rbegin(), freqs.rend());

    for(int i = 0; i < k; ++i)
        result.push_back(freqs[i].second);

    return result;
}

vector<int> topKFrequent_(const vector<int>& nums, int k) {

    priority_queue<pair<int,int>> top_k;
    unordered_map<int,int> freqs;
    vector<int> result;

    for(auto num : nums) freqs[num]++;

    for(auto freq : freqs)
        top_k.push({freq.second, freq.first});

    while(k--){
        result.push_back(top_k.top().second);
        top_k.pop();
    }

    return result;
}

int main() {
    fast;

    vector<int> result = topKFrequent({1}, 1);

    for(auto ele : result)
        cout << ele << " ";

    return 0;
}
