#include<iostream>
#include<set>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/6/problem/B

int main()
{
    int n,m;
    char ch;
    cin >> n >> m >> ch;
    vector<string> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    int nr[] = {-1,0,0,1};
    int nc[] = {0,-1,1,0};

    set<char> st;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(v[i][j]==ch)
            {
                for(int k=0; k<4; k++)
                {
                    int r = i + nr[k];
                    int c = j + nc[k];
                    if(0<=r && r<n && 0<=c && c<m)
                    {
                        if(v[r][c]!=ch && v[r][c]!='.')
                            st.insert(v[r][c]);
                    }
                }
            }
        }
    }

    cout << (int)st.size() << endl;

    return 0;
}
