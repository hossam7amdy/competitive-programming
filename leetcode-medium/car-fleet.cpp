#include<bits/stdc++.h>
using namespace std;

/*
# Approach: sorting + monotonic decreasing stack
    - calculate remaining steps
    - sort by position
    - build monotonic decreasing stack of (fleet)

# Complexity
    - Time: O(nlogn)
    - Space: O(n)
*/

int carFleet_(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int,double>> steps(n);

    for(int i = 0; i < n; ++i){
        double step = (double)(target - position[i]) / speed[i];
        steps[i] = {position[i], step};
    }

    sort(steps.begin(), steps.end());

    stack<double> fleet;
    for(int i = 0; i < n; ++i){
        double step = steps[i].second;
        while(!fleet.empty() && fleet.top() <= step)
            fleet.pop();

        fleet.push(step);
    }

    return fleet.size();
}

// replace stack with constant
int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int n = position.size();
    vector<pair<int,double>> steps(n);

    for(int i = 0; i < n; ++i){
        double step = (double)(target - position[i]) / speed[i];
        steps[i] = {position[i], step};
    }

    sort(steps.begin(), steps.end());

    int fleet = 0;
    double latest = 0;
    for(int i = n-1; i >= 0; --i){
        if(steps[i].second > latest){
            ++fleet;
            latest = steps[i].second;
        }
    }

    return fleet;
}

int main(){

    return 0;
}
