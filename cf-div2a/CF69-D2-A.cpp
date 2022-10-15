#include<iostream>
using namespace std;

/// https://codeforces.com/contest/69/problem/A

int main(){
    int n, v1,v2,v3;
    v1=v2=v3=0;
    cin >> n;
    while(n--){
        int x,y,z;
        cin >> x;
        cin >> y;
        cin >> z;
        v1+=x;
        v2+=y;
        v3+=z;
    }

    if(v1!=0 || v2!=0 || v3!=0)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
