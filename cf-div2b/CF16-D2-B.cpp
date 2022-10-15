#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/16/problem/B

bool sortBySec(const pair<int,int> &a, const pair<int,int> &b)
{
    return a.second > b.second;
}

int main(){
    unsigned int n, m;
    cin >> n >> m;
    vector< pair<unsigned int, int> > v(m);

    for(int i=0; i<m; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end(), sortBySec);

    long long int c = 0;

    for(int i=0; i<m && n!=0; i++)
    {
        if(n>=v[i].first)
        {
            c += v[i].first * v[i].second;
            n -= v[i].first;
        }
        else
        {
            c += n * v[i].second;
            break;
        }
    }

    cout << c;


    return 0;
}
