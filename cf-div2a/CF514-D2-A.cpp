#include<iostream>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/514/problem/A

int main(){
    string s;
    cin >> s;

    for(int i=0; i<(int)s.size(); i++){
        if(i==0 && s[i]=='9')
            continue;
        if(s[i]>='5')
            s[i]='0' + ('9' - s[i]);
    }

    cout << s;

    return 0;
}
