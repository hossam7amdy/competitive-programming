#include <iostream>
using namespace std;

///https://codeforces.com/contest/677/problem/A

int main()
{
    int n, h, f;

    cin >> n >> h;

    for(int i=n; i>0; i--){
        cin >> f;
        if(f>h)
            n++;
    }

    cout << n;

    return 0;
}
