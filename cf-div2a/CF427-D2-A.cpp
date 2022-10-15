#include <iostream>
using namespace std;

///https://codeforces.com/contest/427/problem/A

int main()
{
    int n,cnt=0,pol=0;

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;

        if(num==-1 && pol==0)
            cnt++;
        else if(num==-1 && pol>0)
            pol--;
        else
            pol+=num;
    }

    cout << cnt;

    return 0;
}
