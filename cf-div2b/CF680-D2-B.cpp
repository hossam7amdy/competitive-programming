#include<iostream>
using namespace std;

/// https://codeforces.com/contest/680/problem/B

int main(){
    int n, a, arr[101];
    cin >> n >> a;
    a--;
    for(int i=0; i<n; i++)
        cin >> arr[i];

    int c=arr[a];
    for(int i=1; ((a-i)>=0 || (a+i)<n); i++){
        if((a-i)<0 && arr[a+i]==1)
            c++;
        else if((a+i)>=n && arr[a-i] ==1)
            c++;
        else if((a-i)>=0 && (a+i)<n && arr[a+i]==1 && arr[a-i]==1)
            c+=2;
    }

    cout << c;

    return 0;
}
