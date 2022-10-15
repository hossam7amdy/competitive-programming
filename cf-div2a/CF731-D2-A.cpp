#include <iostream>
using namespace std;

///https://codeforces.com/contest/731/problem/A

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int strt = 0;
    int moves = 0;

    for(int i=0; i<len; i++){
        int index = s[i] - 97;

        int steps = abs(strt - index);

        if(steps > 13)
            moves += 26 - steps;
        else
            moves += steps;

        strt = index;
    };

    cout << moves;

    return 0;
}
