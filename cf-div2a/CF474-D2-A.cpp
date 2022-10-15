#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/474/problem/A

int main(){
    string str{"qwertyuiopasdfghjkl;zxcvbnm,./"};
    char ch;
    string s;
    cin >> ch >> s;

    for(int i=0; i<(int)s.size(); i++){
        auto it = str.find(s[i]);

        if(ch=='R')
            s[i] = str[it-1];
        else
            s[i] = str[it+1];
    }

    cout << s;

    return 0;
}
