// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach: Binary Search
    - For a given amount of time, how can we count the total number of trips completed by all buses within that time?

# Complexity
    - Time: O(nlog(k*n))
    - Space: O(1)
*/

class Solution {
    #define ll long long
    bool canFinish(vector<int>& time, ll curTime, int totalTrips){
        ll countTrips = 0;
        for(auto& t : time){
            countTrips += curTime / t;
            if(countTrips >= totalTrips)
                return true;
        }
        return false;
    }

public:
    ll minimumTime(vector<int>& time, int totalTrips) {
        ll st = 0, en = (ll)totalTrips * *max_element(time.begin(), time.end());

        ll res = en;
        while(st <= en){
            ll mid = st + (en - st) / 2;

            if(canFinish(time, mid, totalTrips))
                en = mid - 1, res = mid;
            else
                st = mid + 1;
        }

        return res;
    }
};

int main(){

    return 0;
}
