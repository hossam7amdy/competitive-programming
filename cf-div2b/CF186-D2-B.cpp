#include<iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp_double(const pair<int, double> &p1, const pair<int, double> &p2){
    if(abs(p1.second - p2.second) < 1e-9)
        return p1.first < p2.first;

    return p1.second > p2.second;
}

int main(){
    int n, t1, t2;
    double k;
    cin >> n >> t1 >> t2 >> k;
    k /= 100;

    vector<pair<int, double> > v;
    for(int i=1; i<=n; i++){
        int a, b;
        cin >> a >> b;

        double res1{(a*t1) - (a*t1*k) + (b*t2)};
        double res2{(b*t1) - (b*t1*k) + (a*t2)};

        v.push_back(make_pair(i, max(res1, res2)));
    }

    sort(v.begin(), v.end(), cmp_double);

    for(auto &pair : v)
        printf("%d %.2f\n", pair.first, pair.second);

    return 0;
}
