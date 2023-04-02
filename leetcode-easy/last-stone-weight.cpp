// https://leetcode.com/problems/last-stone-weight/
#include<bits/stdc++.h>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> heap = priority_queue(stones.begin(), stones.end());

    while(heap.size() > 1){
        int t1 = heap.top(); heap.pop();
        int t2 = heap.top(); heap.pop();

        heap.push(t1 - t2);
    }

    return heap.top();
}

int main() {

    return 0;
}
