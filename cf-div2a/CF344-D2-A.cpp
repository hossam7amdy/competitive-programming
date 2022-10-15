#include <iostream>
using namespace std;

///https://codeforces.com/contest/344/problem/A

int main()
{
    int a,b=0,c=0,n;

    cin >> n;

    while(n--){
        cin >> a;
        if(a!=b)
            c++;
        b=a;
    }

    cout << c;

    return 0;
}
