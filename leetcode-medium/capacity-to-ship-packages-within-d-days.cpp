// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(nlogn)
    - Memory: O(1)
*/

class Solution {
    bool canShip(const vector<int>& weights, int days, int weight){
        int cntDays = 1;
        int curWeight = 0;
        for(auto w : weights){
            if(curWeight + w <= weight){
                curWeight += w;
            }else{
                curWeight = w;
                ++cntDays;
            }

            if(cntDays > days || curWeight > weight)
                return false;
        }

        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int st = 0;
        int en = 25000000;

        int res = en;
        while(st <= en){
            int mid = st + (en - st) / 2;

            if(canShip(weights, days, mid))
                en = mid - 1, res = mid;
            else
                st = mid + 1;
        }

        return res;
    }
};

int main() {
    return 0;
}
