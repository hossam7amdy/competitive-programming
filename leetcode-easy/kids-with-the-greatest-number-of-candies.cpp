// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

#include <bits/stdc++.h>
using namespace std;

vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
    int len = candies.size();
    vector<bool> res(len);

    int max = *max_element(candies.begin(), candies.end());
    for(int i = 0; i < len; ++i)
        res[i] = candies[i] + extraCandies >= max;

    return res;
}

int main(){

    return 0;
}
