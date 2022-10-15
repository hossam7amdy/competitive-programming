#include<iostream>
#include<vector>
#include<set>
using namespace std;

/// https://codeforces.com/contest/365/problem/A

int n,k;
set<char> st;
char arr[]{"0123456789"};

int is_good(){

    if((int)st.size()<k)
        return 0;

    int i=0;
    for(auto it = st.begin(); i<=k; i++,it++){
        if(*it!=arr[i])
            return 0;
    }
    return 1;
}


int main(){

    cin >> n >> k;

    int c = 0;
    while(n--){
        string s;
        cin >> s;
        st.insert(s.begin(), s.end());
        c += is_good();
        st.clear();
    }

    cout << c;


    return 0;
}
