// https://leetcode.com/problems/ipo/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Memory: O(n)
*/

#define node pair<int,int>
#define capital first
#define profit second

int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
    int n = capital.size();
    vector<node> capital_profit;
    priority_queue<int> mxProfits;
    for(int i = 0; i < n; ++i)
        capital_profit.push_back({capital[i], profits[i]});

    sort(capital_profit.begin(), capital_profit.end());

    int idx = 0;
    while(k--){
        while(idx < n && w >= capital_profit[idx].capital)
            mxProfits.push(capital_profit[idx++].profit);
        if(!mxProfits.empty()){
            w += mxProfits.top();
            mxProfits.pop();
        }
    }
    return w;
}

int main() {
    return 0;
}
