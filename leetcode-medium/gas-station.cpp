// https://leetcode.com/problems/gas-station
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(1)
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int gasSum = accumulate(gas.begin(), gas.end(), 0);
    int costSum = accumulate(cost.begin(), cost.end(), 0);

    if(costSum > gasSum) // no solution
        return -1;

    // there is a solution find it
    int sum = 0, res = -1;
    for(int i = 0; i < gas.size(); ++i){
        sum += gas[i] - cost[i];
        if(sum < 0){
            sum = 0;
            res = -1;
        }else if(res == -1)
            res = i;
    }

    return res;
}

int main(){

    return 0;
}
