// https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    int k;
    priority_queue<int> que;
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        for(auto& num : nums){
            que.push(-num);
            if(que.size() > k)
                que.pop();
        }
    }

    int add(int val) {
        que.push(-val);
        if(que.size() > k)
            que.pop();
        return -que.top();
    }
};

int main() {

    return 0;
}
