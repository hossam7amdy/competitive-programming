#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/227/problem/B

int main(){
    int n, m;
    int val;
    cin >> n;
    vector<int> v(100001); // freq array
    for(int i=0; i<n; i++)
    {
        cin >> val;
        v[val] = i;
    }


    cin >> m;
    long long int Vasya=0, Petya=0;

    while(m--)
    {
        cin >> val;
        int idx = v[val];
        Vasya += idx + 1;
        Petya += n - idx;
    }

    cout << Vasya << " " << Petya;

    return 0;
}
