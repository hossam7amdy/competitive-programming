// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(e+v)
    - Space: O(e+v)
*/

class Solution {
    struct Edge{
        int to{};
        bool isForward{};
        Edge(int to, bool isForward):
            to(to), isForward(isForward){
        }
    };

    void dfs(vector<vector<Edge>>& edgeList, vector<bool>& vis, int node, int& count){
        vis[node] = 1;
        for(auto& [neig, isForward] : edgeList[node]){
            if(!vis[neig]){
                count += isForward;
                dfs(edgeList, vis, neig, count);
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<Edge>> edgeList(n);
        for(auto& connection : connections){
            int from = connection[0], to = connection[1];
            edgeList[from].push_back({to, 1});
            edgeList[to].push_back({from, 0});
        }

        int res = 0;
        vector<bool> vis(n, 0);
        dfs(edgeList, vis, 0, res);
        return res;
    }
};

int main(){

    return 0;
}

