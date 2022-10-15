#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/382/problem/A

int main(){
    string s, e, left, right;
    cin >> s >> e;

    int delimiter = s.find('|');

    left = s.substr(0,delimiter); // from begin to delimiter
    right = s.substr(delimiter+1); // from delimiter + 1 to end

    for(int i=0; i<(int)e.size(); i++){
        if(left.size()>=right.size())
            right+=e[i];
        else
            left+=e[i];
    }

    if(left.size()!=right.size())
        cout << "Impossible";
    else
        cout << left << "|" << right;

    return 0;
}
