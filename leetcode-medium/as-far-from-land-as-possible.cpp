// https://leetcode.com/problems/as-far-from-land-as-possible/
#include<bits/stdc++.h>
using namespace std;

/*
# approach 1: for each water cell calculate distance to all water and minimize among all of them

# Complexity
    time: O(water * land)
---

# approach 2: BFS

# Complexity
    time: O(n^2)
*/
class Solution_ {
    #define inf 10000;
    #define x first
    #define y second
    #define cell pair<int,int>
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<cell> land, water;

        for(int x = 0; x < n; ++x)
            for(int y = 0; y < n; ++y){
                if(grid[x][y] == 1)
                    land.push_back({x,y});
                else
                    water.push_back({x,y});
            }

        if(land.empty() || water.empty())
            return -1;

        int res = 0;
        for(auto &[x1, y1] : water){
            int nearsLand = inf;
            for(auto &[x2, y2] : land)
                nearsLand = min(nearsLand, abs(x1 - x2) + abs(y1 - y2));
            res = max(res, nearsLand);
        }

        return res;
    }
};

class Solution {
    #define x first
    #define y second
    #define cell pair<int,int>
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<cell> ready;

        for(int x = 0; x < n; ++x)
            for(int y = 0; y < n; ++y)
                if(grid[x][y] == 1){
                    grid[x][y] = -1;
                    ready.push({x,y});
                }

        if(ready.empty() || ready.size() == n*n)
            return -1;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        while(!ready.empty()){
            auto [x1, y1] = ready.front();
            ready.pop();

            for(int d = 0; d < 4; ++d){
                int x2 = x1 + dx[d];
                int y2 = y1 + dy[d];

                if(isValid(x2, y2, n, grid)){
                    ready.push({x2, y2});
                    grid[x2][y2] = 1 + (grid[x1][y1] == -1 ? 0 : grid[x1][y1]);
                }
            }
        }

        int res = 0;
        for(int x = 0; x < n; ++x)
            for(int y = 0; y < n; ++y)
                res = max(res, grid[x][y]);

        return res;
    }
private:
    bool isValid(int x, int y, int n, vector<vector<int>>& grid){
        return 0 <= x && x < n && 0 <= y && y < n && grid[x][y] == 0;
    }
};

int main(){

    return 0;
}
