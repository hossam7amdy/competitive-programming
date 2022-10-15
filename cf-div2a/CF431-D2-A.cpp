#include <iostream>
using namespace std;

///https://codeforces.com/contest/431/problem/A

int main()
{
    int arr[4], cal=0;
    string s;

    for(int i=0; i<4; i++)
        cin >> arr[i];

    cin >> s;

    for(int i=0; i<s.size(); i++){
        int j = s[i]-48;
        cal+=arr[j-1];
    }

    cout << cal;

    return 0;
}
