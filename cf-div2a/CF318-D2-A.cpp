#include<iostream>
using namespace std;

/// https://codeforces.com/contest/318/problem/A

int main(){
    unsigned long long int n,k;
    cin >> n >> k;

    if(n%2==0){
        if(k>(n/2))
            cout << k  - (n - k);
        else
            cout << k + (k-1); // 2 * k - 1
    }
    else{
        if(k>((n+1)/2))
            cout << k  - ((n+1) - k);
        else
            cout << k + (k-1);
    }

    return 0;
}
