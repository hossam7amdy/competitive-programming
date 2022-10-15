#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/768/problem/A

int main(){
    int arr[100001]; // 1 2 2 2 2 7
    int num, c=0;
    cin >> num;

    for(int i=0; i<num; i++)
        cin >> arr[i];

    sort(arr, arr+num);

    for(int i=1; i<num-1; i++){
        if(arr[0]<arr[i] && arr[i]<arr[num-1])
            c++;
    }

    cout << c;

    return 0;
}
