#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/796/problem/B

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> v(n+1,false);

    int pos;
    while(m--){
        cin >> pos;
        v[pos] = true;
    }

    pos = 1;
    while(k--){
        int i,j;
        cin >> i >> j;
        if(pos == i && !v[pos])
            pos = j;
        else if(pos == j && !v[pos])
            pos = i;
    }

    cout << pos;

    //cerr<<"Time : "<<(float)clock()/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
