// https://leetcode.com/problems/as-far-from-land-as-possible/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: for each water cell calculate distance to all water and minimize among all of them

# Complexity
    time: O(water * land)
*/

class Solution {
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

int main(){

    return 0;
}
