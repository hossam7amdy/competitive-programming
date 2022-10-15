#include<iostream>
#include<set>
using namespace std;

///https://codeforces.com/contest/228/problem/A

int main(){
    set<int> st;

    for(int i=0; i<4; i++){
        int next;
        cin >> next;
        st.insert(next);
    }

    cout << 4 - st.size();

    return 0;
}
