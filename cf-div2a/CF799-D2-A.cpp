#include<iostream>
#include<cmath>
using namespace std;

/// https://codeforces.com/contest/709/problem/A

int main(){
    double n,t,k,d;
    double t1, t2;

    cin >> n >> t >> k >> d;
    t1 = ceil(n/k) * t; // The Oven will have to work the hole t time to bake k cakes.

    if(t1<=d){
        cout << "NO";
        return 0;
    }

    t2 = t + d;

    if(t2<t1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
