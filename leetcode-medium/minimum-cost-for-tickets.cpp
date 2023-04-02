// https://leetcode.com/problems/minimum-cost-for-tickets/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: DP
*/

class Solution {
    static const int MAX = 365 + 1;
    int memo[MAX];

    int dp(vector<int>& days, vector<int>& costs, int idx){
        if(idx >= days.size())
            return 0;

        auto &ret = memo[idx];
        if(ret != -1)
            return ret;

        int jump1 = lower_bound(days.begin(), days.end() , days[idx] + 1) - days.begin();
        int jump2 = lower_bound(days.begin(), days.end() , days[idx] + 7) - days.begin();
        int jump3 = lower_bound(days.begin(), days.end() , days[idx] + 30) - days.begin();

        int choose1 = costs[0] + dp(days, costs, jump1);
        int choose2 = costs[1] + dp(days, costs, jump2);
        int choose3 = costs[2] + dp(days, costs, jump3);

        return ret = min(choose1, min(choose2, choose3));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(memo, -1, sizeof(memo));
        return dp(days, costs, 0);
    }
};

int main(){

    return 0;
}
