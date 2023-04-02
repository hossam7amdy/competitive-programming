// https://leetcode.com/problems/longest-cycle-in-a-graph/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: dfs
# approach: O(E+V)
*/

class Solution {
    int cycleLen = -1;
    void dfs(vector<vector<int>>& adjList, vector<bool>&vis, int node, vector<int>& nodes){
        if(vis[node]){
            int idx = 0;
            while(idx < nodes.size()){
                if(nodes[idx++] != node)
                    continue;

                cycleLen = max(cycleLen, (int)nodes.size() - idx + 1);
                break;
            }
            return;
        }

        vis[node] = 1;
        nodes.push_back(node);
        for(auto& neig : adjList[node])
            dfs(adjList, vis, neig, nodes);
    }

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> adjList(n);
        for(int node = 0; node < n; ++node){
            if(edges[node] == -1) continue;
            adjList[node].push_back(edges[node]);
        }

        vector<bool> vis(n, 0);
        for(int node = 0; node < n; ++node){
            vector<int> nodes;
            if(!vis[node])
                dfs(adjList, vis, node, nodes);
        }
        return cycleLen;
    }
};

int main(){

    return 0;
}
