#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, a, b;
    cin >> n >> a >> b;

    while(n--){
        long long int val;
        cin >> val;

        cout << ((val*a)%b)/a << " ";
    }

    return 0;
}
