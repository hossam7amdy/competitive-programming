// https://leetcode.com/problems/n-th-tribonacci-number/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: DP
    tri[n] = tri[n-1] + tri[n-2] + tri[n-3]

#Complexity
    - Time: O(n)
    - Space: O(1)
*/


// 1- Memoization O(n) time & space
int dp(int n, vector<int>& memo){
    if(n <= 0)
        return 0;

    auto &ret = memo[n];
    if(ret != -1)
        return ret;

    if(n == 1 || n == 2)
        return 1;

    return ret = dp(n - 1, memo) + dp(n - 2, memo)  + dp(n - 3, memo);
}

int tribonacci(int n) {
    vector<int> memo(n+1, -1);
    return dp(n, memo);
}

// 2- DP O(n) time & space
int tribonacci(int n) {
    if(n == 0) return 0;

    vector<int> dp(n+5);
    dp[0] = 0, dp[1] = 1, dp[2] = 1;
    for(int i = 3; i <= n; ++i){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }

    return dp[n];
}

// 3- DP + Greedy: Time O(n) & Space O(1)
int tribonacci(int n) {
    if(n == 0) return 0;

    int x = 0, y = 1, z = 1;
    for(int i = 3; i <= n; ++i){
        int ny = z, nx = y;
        z = z + y + x;
        y = ny, x = nx;
    }
    return z;
}


int main(){

    return 0;
}
