// https://leetcode.com/problems/number-of-operations-to-make-network-connected/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(v+e)
    - Space: O(v+e)
*/

class Solution {
    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int node){
        if(vis[node])
            return;

        vis[node] = 1;
        for(auto& neig : adjList[node])
            dfs(adjList, vis, neig);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size())
            return -1;

        vector<vector<int>> adjList(n);
        for(auto& connection : connections){
            int from = connection[0], to = connection[1];
            adjList[from].push_back(to);
            adjList[to].push_back(from);
        }

        int components = 0;
        vector<bool> vis(n,0);

        for(int node = 0; node < n; ++node){
            if(vis[node]) continue;

            dfs(adjList, vis, node);
            components++;
        }

        return components - 1;
    }
};

int main(){

    return 0;
}

