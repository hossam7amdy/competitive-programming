#include <iostream>
using namespace std;

///https://codeforces.com/contest/734/problem/A

int main()
{
    int n, a=0, d=0;
    string str;

    cin >> n;
    cin >> str;

    for(int i=0; i<n; i++){
        if(str[i]=='A')
            a++;
        else if(str[i]=='D')
            d++;
    }

    if(a>d)
        cout << "Anton";
    else if(a<d)
        cout << "Danik";
    else
        cout << "Friendship";


    return 0;
}
