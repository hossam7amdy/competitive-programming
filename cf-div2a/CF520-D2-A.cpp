#include<iostream>
#include<set>
using namespace std;

/// https://codeforces.com/contest/520/problem/A

int main(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    if(n<26){
        cout << "NO";
        return 0;
    }

    set<char> st;

    for(auto& ch : s){
        if((int)ch>=97)
            st.insert(ch-32);
        else
            st.insert(ch);
    }

    if(st.size()==26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
