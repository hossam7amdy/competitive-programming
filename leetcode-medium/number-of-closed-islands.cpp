// https://leetcode.com/problems/number-of-closed-islands/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;
    bool isValidDir(int r, int c){
        return 0 <= r && r < rows && 0 <= c && c < cols;
    }

    bool dfs(vector<vector<int>>& grid, int r, int c){
        if(!isValidDir(r, c))
            return false;
        if(grid[r][c])
            return true;

        grid[r][c] = 1;

        bool top   = dfs(grid, r + 1, c);
        bool down  = dfs(grid, r, c + 1);
        bool left  = dfs(grid, r - 1, c);
        bool right = dfs(grid, r, c - 1);

        return top && down && left && right;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int closedIsland = 0;
        for(int r = 0; r < grid.size(); ++r){
            for(int c = 0; c < grid[r].size(); ++c){
                if(!grid[r][c] && dfs(grid, r, c))
                    ++closedIsland;
            }
        }

        return closedIsland;
    }
};

int main(){

    return 0;
}
