//https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

#include <bits/stdc++.h>
using namespace std;

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    int spellsLen = (int)spells.size();
    vector<int> res(spellsLen);

    sort(potions.begin(), potions.end());
    for(int i = 0; i < spellsLen; ++i){
        int postionsLen = potions.size();
        long long target = (success - 1) / spells[i] + 1;
        int idx = lower_bound(potions.begin(), potions.end(), target) - potions.begin();
        int pairs = idx == postionsLen ? 0 : postionsLen - idx;
        res[i] = pairs;
    }

    return res;
}

int main(){

    return 0;
}
