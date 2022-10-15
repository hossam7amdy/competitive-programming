#include<iostream>
using namespace std;

/// https://codeforces.com/contest/766/problem/A

int main(){
    string a, b;

    cin >> a >> b;

    if(a==b)
        cout << -1;
    else if((int)a.size()>(int)b.size())
        cout << (int)a.size();
    else
        cout << (int)b.size();


    return 0;
}
