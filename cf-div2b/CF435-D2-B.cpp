#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    string s;
    cin >> s >> k;

    for(int i=0; i<(int)s.size(); ++i){
        int mx = s[i]-'0';
        int idx = -1;

        for(int j=i+1; j<(int)s.size(); ++j){
            if(s[j]-'0' > mx && k >= j-i){
                idx = j;
                mx = s[j]-'0';
            }
        }

        if(idx == -1) continue;
        k = k - (idx-i);

        for(int j=idx; j>i; --j)
            swap(s[j-1], s[j]);
    }

    cout << s << endl;

    return 0;
}
