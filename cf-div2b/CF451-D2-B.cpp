#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/451/problem/B

int main()
{
    int sz;
    cin >> sz;
    vector<unsigned int> v(sz);
    int st = 0,en = 0;
    bool flag = false;
    for(int i=0; i<sz; i++)
    {
        cin >> v[i];
        if(i)
        {
            if(v[i-1]>v[i] && !flag)
            {
                st = i-1;
                flag = true;
            }
            if(v[i-1]>v[i])
                en = i;
        }
    }

    reverse(v.begin()+st, v.begin()+en+1);

    for(int i=1; i<sz; i++)
    {
        if(v[i-1]>v[i])
        {
            cout << "no";
            return 0;
        }
    }

    cout << "yes\n" << st+1 << " " << en+1;

    return 0;
}
