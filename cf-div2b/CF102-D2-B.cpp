#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/102/problem/B

int main(){
    string s;
    cin >> s;

    if((int)s.size()==1)
    {
        cout << 0;
        return 0;
    }

    int c = 0, x = 11;

    while(x>9)
    {
        x = 0;
        for(int i=0; i<(int)s.size(); i++)
        {
            x += (s[i]-'0');
        }
        ostringstream oss;
        oss << x;
        s = oss.str();
        c++;
    }

    cout << c;

    return 0;
}
