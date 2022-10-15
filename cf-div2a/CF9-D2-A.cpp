#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/9/problem/A

int main(){
    int Y,W;
    cin >> Y >> W;

    W = max (Y,W);
    W = 6 - W + 1;

    if(W==1)
        cout << 1 << "/" << 6;
    else if(W==2)
        cout << 1 << "/" << 3;
    else if(W==3)
        cout << 1 << "/" << 2;
    else if(W==4)
        cout << 2 << "/" << 3;
    else if(W==5)
        cout << 5 << "/" << 6;
    else if(W==6)
        cout << 1 << "/" << 1;

    return 0;
}
