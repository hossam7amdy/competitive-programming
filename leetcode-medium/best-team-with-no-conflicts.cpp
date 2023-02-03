// https://leetcode.com/problems/best-team-with-no-conflicts/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: DP

#Complexity
    - Time: O(n^2)
    - Space: O(n)
*/

class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> sortedByAge(n);
        for(int i = 0; i < n; ++i)
            sortedByAge[i] = {ages[i], scores[i]};

        sort(sortedByAge.begin(), sortedByAge.end());

        vector<int> dp(n,0);
        for(int i = n - 1; i >= 0; --i){
            for(int j = i; j < n; ++j){
                if(sortedByAge[i].second <= sortedByAge[j].second)
                    dp[i] = max(dp[i], sortedByAge[i].second + dp[j]);
            }
        }

        int res = 0;
        for(auto &val : dp)
            res = max(res, val);
        return res;
    }
};

int main(){

    return 0;
}
