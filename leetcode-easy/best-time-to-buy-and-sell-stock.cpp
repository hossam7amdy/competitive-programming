#include <bits/stdc++.h>
using namespace std;

/*
    You want to maximize your profit by choosing a single day to buy one stock and choosing
    a different day in the future to sell that stock.
    EX. [7,1,5,3,6,4] => 5

# Approach 1: DP
    - keep minimum price among all prices
    - for each price maximize your profit

# Complexity
    - Time complexity: O(n)
    - Space complexity: O(1)
*/

int maxProfit(vector<int>& prices) {
    int minVal = 1e4, profit = 0;
    for(auto &price : prices){
        minVal = min(minVal, price);
        profit = max(profit, price - minVal);
    }

    return profit;
}

int main(){

    return 0;
}
