#include<iostream>
using namespace std;

/// https://codeforces.com/contest/265/problem/A

int main(){
    string s,t;
    int pos = 0;

    cin >> s >> t;

    for(int i=0; i<(int)t.size() && pos<(int)s.size()-1; i++){
        if(t[i]==s[pos])
            pos++;
    }

    pos++; //1-based
    cout << pos;

    return 0;
}
