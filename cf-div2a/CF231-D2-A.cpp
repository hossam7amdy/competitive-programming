#include <iostream>
using namespace std;

///https://codeforces.com/contest/231/problem/A

int main()
{
    int n, s=0;

    cin >> n;

    while(n--){
        int p,v,t;
        cin >> p >> v >> t;
        if((p+v+t)>=2)
            s++;
    }

    cout << s << endl;

    return 0;
}
