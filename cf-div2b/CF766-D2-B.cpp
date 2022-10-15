#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/766/problem/B

int main()
{
    int n;
    cin >> n;
    vector<unsigned int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];

    sort(v.begin(), v.end());

    for(int i=1; i<n-1; ++i){
        if(v[i-1]+v[i]>v[i+1]){
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    //cerr<<"Time : "<<(float)clock()/CLOCKS_PER_SEC<<" s"<<endl;
    return 0;
}
