// https://leetcode.com/problems/minimum-path-sum/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: DP
# Complexity: O(m*n)
*/

class Solution {
    int dp(vector<vector<int>>& grid, vector<vector<int>>& memo, int r, int c){
        if(r == grid.size() || c == grid[r].size())
            return 1e9;

        if(r == grid.size() - 1 && c == grid[r].size() - 1)
            return grid[r][c];

        auto& ret = memo[r][c];
        if(ret != -1)
            return ret;

        int down = dp(grid, memo, r, c + 1);
        int right = dp(grid, memo, r + 1, c);
        return ret = grid[r][c] + min(down, right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));

        return dp(grid, memo, 0, 0);
    }
};

int main(){

    return 0;
}
