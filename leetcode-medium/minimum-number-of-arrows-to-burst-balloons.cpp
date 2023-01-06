// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

#include<bits/stdc++.h>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    int arrows = 1;
    int xEnd = points[0][1];
    for(int i = 1; i < points.size(); ++i){
        if(xEnd >= points[i][0])
            xEnd = min(xEnd, points[i][1]);
        else{
            ++arrows;
            xEnd = points[i][1];
        }
    }

    return arrows;
}

int main(){

    return 0;
}
