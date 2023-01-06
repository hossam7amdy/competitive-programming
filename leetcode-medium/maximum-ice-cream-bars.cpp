// https://leetcode.com/problems/maximum-ice-cream-bars

#include<bits/stdc++.h>
using namespace std;

// Approach 1: sort
int maxIceCream(vector<int>& costs, int coins) { // O(nlogn)
    sort(costs.begin(), costs.end());

    int bars = 0;
    for(const auto &cost : costs){
        if(cost > coins) break;
        coins -= cost;
        ++bars;
    }

    return bars;
}

// Approach 2: count sort
int maxIceCream(vector<int>& costs, int coins) { // O(n + m)
    int max = *max_element(costs.begin(), costs.end());
    vector<int> coinFreq(max+1, 0);
    for(auto &cost : costs)
        ++coinFreq[cost];

    int  iceCream = 0;
    for(int cost = 1; cost <= max && coins; ++cost){
        if(coinFreq[cost] == 0) continue;

        int count = min(coinFreq[cost], coins / cost);

        iceCream += count;
        coins -= count * cost;
    }

    return iceCream;
}

int main(){

    return 0;
}
