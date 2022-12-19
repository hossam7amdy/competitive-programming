
#include<bits/stdc++.h>
using namespace std;

/*
# Approach 1: stack
    - push & fix with bigger temperature

# Complexity
    - Time: O(n)
    - Space: O(n)
*/

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n,0);
    stack<int> stk;

    for(int day = 0; day < n; ++day){
        while(!stk.empty() && temperatures[stk.top()] < temperatures[day]){
            result[stk.top()] = day - stk.top();
            stk.pop();
        }

        stk.push(day);
    }

    return result;
}

int main(){

    return 0;
}
