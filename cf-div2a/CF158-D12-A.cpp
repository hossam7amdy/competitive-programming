#include<iostream>
using namespace std;

/// https://codeforces.com/contest/158/problem/A

int main(){
    int arr[51];
    int n, k, c=0;
    cin >> n >> k;
    k--; // Zero-based
    while(n--)
        cin >> arr[c++];

    n=c;
    c=0;

    for(int i=0; i<n; i++){
        if(arr[i]>=arr[k] && arr[i]>0)
            c++;
        else
            break;
    }

    cout << c;


    return 0;
}
