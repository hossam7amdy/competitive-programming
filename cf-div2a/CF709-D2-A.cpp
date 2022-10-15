#include<iostream>
using namespace std;

/// https://codeforces.com/contest/709/problem/A

int main(){
    int n, b, d, a, c=0, sum=0;
    cin >> n >> b >> d;
    while(n--){
        cin >> a;
        if(a>b)
            continue;
        sum += a;
        if(sum>d){
            sum=0;
            c++;
        }
    }

    cout << c;

    return 0;
}
