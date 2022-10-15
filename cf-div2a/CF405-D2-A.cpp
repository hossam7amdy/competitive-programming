#include <iostream>
#include <algorithm>
using namespace std;

///https://codeforces.com/contest/405/problem/A

int main()
{
    int arr[101], len;

    cin >> len;
    for(int i=0; i<len; i++){
        int n;
        cin >> n;
        arr[i] = n;
    }

    sort(arr,arr+len);

    for(int i=0; i<len; i++)
        cout << arr[i] << " ";

    return 0;
}
