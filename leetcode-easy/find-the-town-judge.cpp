// https://leetcode.com/problems/find-the-town-judge/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: Graph

#Complexity
    - Time O(n+m)
    - Space O(n+m)
*/

int findJudge(int n, vector<vector<int>>& trust) {
    vector<int> trustedBy(n+1);
    vector<vector<int>> graph(n+1);

    for(auto &edge : trust){
        int a = edge[0], b = edge[1];
        graph[a].push_back(b);
    }

    for(int node = 1; node <= n; ++node)
        for(auto &neigh : graph[node])
            ++trustedBy[neigh];

    for(int judge = 1; judge <= n; ++judge)
        if(trustedBy[judge] == (n-1) && graph[judge].size() == 0)
            return judge;

    return -1;
}

int main(){

    return 0;
}

