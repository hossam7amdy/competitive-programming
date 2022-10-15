#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/296/problem/A

int main(){
    const int MAX = 1001;
    int freq[MAX]{0};
    int n,fr;

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> fr;
        freq[fr]++;
    }

    if(n==1){
        cout << "YES";
        return 0;
    }

    fr = -1;
    for(int i=0; i<MAX; i++)
        fr = max(fr,freq[i]);


    n = (n+1)/2;

    if(fr>n)
        cout << "NO";
    else
        cout << "YES";


    return 0;
}
