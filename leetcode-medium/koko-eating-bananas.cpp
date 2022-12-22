#include<bits/stdc++.h>
using namespace std;

/*
#Intuition
    It is intuitive to know that k will always be between 1 and max(pile).

#Approach: Monotonic Binary Search
    - Binary search from 1 to max(pile) and minimize among all values.

#Complexity
    - Time: O(logn) n = max pile value (e.g., 1e9)
    - Space: O(1)
*/

class Solution {
private:
    bool canEat(const vector<int> &piles, int h, int k){
        for (auto pile : piles){
            int time = (pile-1) / k + 1;
            h -= time;

            if (h < 0)
                return false;
        }

        return true;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h){
        int k = 0;
        int st = 1, en = 1e9;

        while (st <= en){
            int mid = st + (en - st) / 2;

            if (canEat(piles, h, mid))
                en = mid - 1, k = mid;
            else
                st = mid + 1;
        }

        return k;
    }
};

int main(){

    return 0;
}
