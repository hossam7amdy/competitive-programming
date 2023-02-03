// https://leetcode.com/problems/zigzag-conversion/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach 1: Simulate Zig-Zag Movement

#Complexity
    - Time: O(n*numRows)
    - Space: O(n*numRows)
*/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> grid(numRows);

        int idx = 0;
        while(idx < s.size()){
            for(int i = 0; i < numRows && idx < s.size(); ++i)
                grid[i].push_back(s[idx++]);

            for(int i = numRows - 2; i > 0 && idx < s.size(); --i)
                grid[i].push_back(s[idx++]);
        }

        string res = "";
        for(auto &row : grid)
            for(auto &ch : row)
                res += ch;

        return res;
    }
};

int main(){

    return 0;
}
