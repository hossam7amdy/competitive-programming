// https://leetcode.com/problems/fruit-into-baskets/
#include<bits/stdc++.h>
using namespace std;

/*
# approach: Sliding Window

# Complexity:
    - time O(n)
    - space O(n)
*/

// O(n)
int totalFruit(vector<int>& fruits) {
    unordered_map<int,int> basket;

    int left = 0, res = 0, total = 0;
    for(auto &fr : fruits){
        total++;
        basket[fr]++;

        while(basket.size() > 2){
            total--;
            int curFr = fruits[left++];

            if(--basket[curFr] == 0)
                basket.erase(curFr);
        }

        res = max(res, total);
    }
    return res;
}

int main(){

    return 0;
}
