#include<iostream>
#include<string>
using namespace std;

/// https://codeforces.com/contest/746/problem/B

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = "";

    res += s[0];

    if(n%2==0)
    {
        for(int i=1; i<n;)
        {
            res+=s[i++];
            if(i<n)
                res = s[i++] + res;
        }
    }
    else
    {
        for(int i=1; i<n;)
        {
            res = s[i++] + res;
            if(i<n)
                res += s[i++];
        }
    }

    cout << res;

    return 0;
}
