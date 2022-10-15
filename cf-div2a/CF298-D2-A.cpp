#include<iostream>
#include<string>
using namespace std;

/// https://codeforces.com/contest/298/problem/A

int main(){
    string s;
    int sz;
    cin >> sz >> s;

    int R1, R2, L1, L2;
    R1=R2=L1=L2=0;

    for(int i=0; i<sz; i++){
        if(s[i]=='R' && s[i-1]=='.')
            R1 = i+1;
        if(s[i]=='R' && s[i+1]=='L')
            R2 = i+1;
        else if(s[i]=='R' && s[i+1]=='.')
            R2 = i+2;

        if(s[i]=='L' && s[i-1]=='.')
            L1 = i;
        if(s[i]=='L')
            L2 = i+1;
    }

    if(R1 && R2)
        cout << R1 << " " << R2;
    else if(R1)
        cout << R1 << " " << R1;

    if(R1||R2)
        return 0;

    if(L1 && L2)
        cout << L2 << " " << L1;
    else
        cout << L1 << " " << L1;

    return 0;
}
