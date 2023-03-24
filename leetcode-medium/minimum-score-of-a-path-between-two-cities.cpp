// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct city {
        int to, cost;

        city(int to, int cost):
            to(to), cost(cost){

        }
    };

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector< vector<city> > adjList(n);

        for(auto& road : roads){
            int from = road[0] - 1, to = road[1] - 1, cost = road[2];
            adjList[from].push_back({to, cost});
            adjList[to].push_back({from, cost});
        }

        int res = 1e4;
        queue<int> ready;
        vector<bool> vis(n, 0);

        ready.push(0);
        vis[0] = 1;

        while(!ready.empty()){
            auto cur = ready.front();
            ready.pop();

            for(auto& neigh : adjList[cur]){
                res = min(res, neigh.cost);
                if(!vis[neigh.to]){
                    vis[neigh.to] = 1;
                    ready.push(neigh.to);
                }
            }
        }

        return res;
    }
};

int main(){

    return 0;
}

