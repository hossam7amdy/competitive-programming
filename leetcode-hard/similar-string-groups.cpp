// https://leetcode.com/problems/similar-string-groups/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSimilar(string& s1, string& s2){
        int diff = 0;
        for(int i = 0; i < s1.size(); ++i)
            if(s1[i] != s2[i])
                ++diff;

        return diff == 0 || diff == 2;
    }

    void dfs(vector<vector<int>>& adjList, vector<bool>& vis, int node){
        vis[node] = 1;
        for(auto& neig : adjList[node])
            if(!vis[neig])
                dfs(adjList, vis, neig);
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adjList(n);

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j)
                if(isSimilar(strs[i], strs[j])){
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
        }

        int count = 0;
        vector<bool> vis(n, 0);
        for(int node = 0; node < n; ++node){
            if(!vis[node]){
                ++count;
                dfs(adjList, vis, node);
            }
        }

        return count;
    }
};
int main(){

    return 0;
}
