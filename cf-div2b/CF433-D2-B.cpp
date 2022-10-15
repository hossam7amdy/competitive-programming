#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/433/problem/B

int main()
{
    int n;
    cin >> n;
    n++; // one-based
    vector<unsigned int> v(n,0);
    vector<long long int> cumulated(n,0);
    vector<long long int> cumul_sorted(n,0);

    for(int i=1; i<n; i++)
    {
        cin >> v[i];
        cumulated[i] = v[i] + cumulated[i-1];
    }

    sort(v.begin(), v.end());

    for(int i=1; i<n; i++)
    {
        cumul_sorted[i] = v[i] + cumul_sorted[i-1];
    }

    int m;
    cin >> m;
    while(m--)
    {
        int type, l, r;
        cin >> type >> l >> r;
        if(type==1)
            cout << cumulated[r] - cumulated[l-1] << endl;
        else
            cout << cumul_sorted[r] - cumul_sorted[l-1] << endl;
    }


    return 0;
}
