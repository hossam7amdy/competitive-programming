// https://leetcode.com/problems/number-of-enclaves/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int rows, cols;

    bool isValidDir(int r, int c){
        return 0 <= r && r < rows && 0 <= c && c < cols;
    }

    void dfs(vector<vector<int>>& grid, int r, int c){
        if(!isValidDir(r, c) || !grid[r][c])
            return;

        grid[r][c] = 0;
        dfs(grid, r + 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        for(int r = 0; r < rows; ++r){
            dfs(grid, r,        0);
            dfs(grid, r, cols - 1);
        }
        for(int c = 0; c < cols; ++c){
            dfs(grid, 0,        c);
            dfs(grid, rows - 1, c);
        }

        int res = 0;
        for(int r = 0; r < rows; ++r){
            for(int c = 0; c < cols; ++c)
                if(grid[r][c]) ++res;
        }

        return res;
    }
};

int main(){

    return 0;
}
