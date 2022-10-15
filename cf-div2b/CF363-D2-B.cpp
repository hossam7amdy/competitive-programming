#include<iostream>
#include<set>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/363/problem/B

int main()
{
    int n,k;
    scanf("%d%d", &n,&k);
    n++; // one-based
    vector<int> v(n,0);
    for(int i=1; i<n; i++)
    {
        cin >> v[i];
        v[i] = v[i] + v[i-1];
    }

    vector<int> acc(n,0);

    acc[k] = v[k];
    for(int i=k+1; i<n; i++)
    {
        acc[i] = v[i] - v[i-k];
    }

    int mn = acc[k], idx = k;
    for(int i=k; i<n; i++)
    {
        if(acc[i]<=mn)
        {
            mn = acc[i];
            idx = i-k+1;
        }

    }
    cout << idx << endl;


    return 0;
}
