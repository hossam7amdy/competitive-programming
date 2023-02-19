// https://leetcode.com/problems/shortest-path-with-alternating-colors/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Memory: O(n)
*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> red(n), blue(n);

        for(auto &edge : redEdges)
            red[edge[0]].push_back(edge[1]);
        for(auto &edge : blueEdges)
            blue[edge[0]].push_back(edge[1]);

        vector<int> res(n,-1);
        res[0] = 0;

        bfs(red, blue, res, 1);
        bfs(red, blue, res, 0);

        return res;
    }
private:

    #define GRAPH vector<vector<int>>
    void bfs(const GRAPH& red, const GRAPH& blue, vector<int>& res, bool isRed){
        int n = res.size();
        queue<int> ready;
        GRAPH vis(n, vector<int>(2, 0));

        ready.push(0);
        vis[0][isRed] = 1;

        int level = 1;
        while(!ready.empty()){
            auto &graph = isRed ? blue : red;
            for(int sz = ready.size(); sz; --sz){
                int cur = ready.front();
                ready.pop();

                for(auto &neig : graph[cur]){
                    if(vis[neig][isRed])
                        continue;

                    ready.push(neig);
                    vis[neig][isRed] = 1;

                    if(res[neig] == -1)
                        res[neig] = level;
                    else
                        res[neig] = min(res[neig], level);
                }
            }
            isRed = !isRed;
            ++level;
        }
    }
};


int main(){

    return 0;
}
