#include<iostream>
using namespace std;

/// https://codeforces.com/contest/686/problem/A

int main(){
    int num, d, c=0;
    unsigned long long int x;
    char ch;

    cin >> num >> x;

    while(num--){
        cin >> ch >> d;

        if(ch == '+')
            x+=d;
        else if(ch=='-' && x>=d)
            x-=d;
        else
            c++;
    }

    cout << x << " " << c;

    return 0;
}
