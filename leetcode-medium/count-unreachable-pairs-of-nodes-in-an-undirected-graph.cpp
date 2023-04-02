// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: dfs
# Complexity: O(E+V)
*/

class Solution {
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int node, int& count){
        count++;
        vis[node] = 1;
        for(auto& neig : adjList[node]){
            if(!vis[neig])
                dfs(adjList, vis, neig, count);
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for(auto& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<bool> vis(n, 0);
        long long globalCount = 0, res = 0;
        for(int node = 0; node < n; ++node){
            if(!vis[node]){
                int localCount = 0;
                dfs(adjList, vis, node, localCount);
                res += localCount * globalCount;
                globalCount += localCount;
            }
        }

        return res;
    }
};

int main(){

    return 0;
}
