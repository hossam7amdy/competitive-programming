// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree
#include <bits/stdc++.h>
using namespace std;


class Solution {
    vector<vector<int>> graph;

    int dfs(int node, int parent, const vector<bool> &hasApple){
        int totalTime = 0;
        for(int neigh : graph[node]){
            if(neigh == parent) continue;

            int childTime = dfs(neigh, node, hasApple);

            if(childTime || hasApple[neigh])
                totalTime += 2 + childTime;
        }

        return totalTime;
    }
public:
    // O(n)
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        graph.resize(n);

        for(auto edge : edges){
            int from = edge[0], to = edge[1];

            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        return dfs(0,-1,hasApple);
    }
};

int main(){

    return 0;
}
