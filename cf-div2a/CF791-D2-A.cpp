#include <iostream>
using namespace std;

///https://codeforces.com/contest/791/problem/A

int main()
{
    int n, s=0;

    cin >> n;

    while(n--){
        int p,v,t;
        cin >> p >> v >> t;
        s+=(p+v+t>=2);
    }

    cout << s << endl;

    return 0;
}
