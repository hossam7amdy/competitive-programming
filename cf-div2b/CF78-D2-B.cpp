#include<iostream>
using namespace std;

/// https://codeforces.com/contest/78/problem/B

int main(){
    int n;
    cin >> n;

    string ans = "ROYGBIV";

    for(int i = 7; i<n; i++)
        ans += ans[i-4];


    cout << ans;

    return 0;
}
