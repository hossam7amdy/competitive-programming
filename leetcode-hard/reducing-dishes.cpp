// https://leetcode.com/problems/reducing-dishes/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: DP
*/

class Solution {
    static const int MAX = 500 + 1;
    int memo[MAX][MAX];

    int dp(vector<int>& satisfaction, int idx, int time){
        if(idx == satisfaction.size())
            return 0;

        auto& ret = memo[idx][time];
        if(ret != -1)
            return ret;

        int pick = satisfaction[idx] * time + dp(satisfaction, idx + 1, time + 1);
        int leave = dp(satisfaction, idx + 1, time);

        return ret = max(pick, leave);
    }

public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        satisfaction.insert(satisfaction.begin(), 0);

        memset(memo, -1, sizeof(memo));

        return dp(satisfaction, 0, 0);
    }
};

int main(){

    return 0;
}
