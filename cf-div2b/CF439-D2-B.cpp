#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<long long> v(n);
    for(int i=0; i<n; ++i) cin >> v[i];

    sort(v.begin(), v.end());
    long long res{};
    for(int i=0; i<n; ++i){
        res += v[i] * x;
        x -= (x>1);
    }
    cout << res;

    return 0;
}
