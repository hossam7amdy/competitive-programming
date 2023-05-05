// https://leetcode.com/problems/boats-to-save-people/

#include <bits/stdc++.h>
using namespace std;

int numRescueBoats(vector<int>& people, int limit) {
    sort(people.begin(), people.end());

    int numOfBoats = 0;
    int st = 0, en = people.size() - 1;
    while(st <= en){
        if(people[st] + people[en] <= limit)
            ++st;
        --en;
        ++numOfBoats;
    }

    return numOfBoats;
}

int main(){

    return 0;
}
