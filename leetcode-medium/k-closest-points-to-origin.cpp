// https://leetcode.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue< pair<int,int> > heap;
    for(int i = 0; i < points.size(); ++i){
        int dist = points[i][0]*points[i][0] + points[i][1]*points[i][1];
        heap.push({-dist,i});
    }

    vector<vector<int>> res;
    while(k--){
        auto [_,idx] = heap.top(); heap.pop();
        res.push_back(points[idx]);
    }

    return res;
}

int main() {

    return 0;
}
