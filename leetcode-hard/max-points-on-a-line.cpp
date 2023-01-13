// https://leetcode.com/problems/max-points-on-a-line
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n * nlogn)
    - Space: O(1)
*/

int maxPoints(vector<vector<int>>& points) {
    int res = 0;
    int sz = points.size();

    for(int i = 0; i < sz; ++i){
        map<pair<int,int>,int> slopeFreq;
        int maxPoints = 0;
        int x1 = points[i][0], y1 = points[i][1];

        for(int j = i + 1; j < sz; ++j){
            int x2 = points[j][0], y2 = points[j][1];

            int xDif = x2 - x1;
            int yDif = y2 - y1;

            int g = __gcd(xDif, yDif);
            xDif /= g;
            yDif /= g;

            pair<int,int> slope = {xDif, yDif};
            maxPoints = max(maxPoints, ++slopeFreq[slope]);
        }
        res = max(res, maxPoints);
    }

        return res + 1;
}

int main(){

    return 0;
}
