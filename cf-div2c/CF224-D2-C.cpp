#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define x first
#define y second
#define ll long long

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main(){
    fast_IO();

    map<char,char> mp; // easy comparison
    mp[']'] = '[';
    mp[')'] = '(';

    string input;
    cin >> input;

    stack<pair<char, int>> st; // <bracket, position>
    for(int i = 0; i < (int)input.length(); ++i){
        char ch = input[i];

        // remove any valid sequence
        if(!st.empty() && mp[ch] == st.top().first)
           st.pop();
        else
           st.push({ch, i});
    }

    // split input
    while(!st.empty()){
        auto top = st.top();
        st.pop();
        input[top.second] = '0';
    }

    input += '0'; // to process all input at once

    int cnt1{}, cnt2{};
    string sub1{}, sub2{};

    // find sequence with largest number of <<[>>
    for(int i = 0; i < (int)input.length(); ++i){
        if(input[i] == '0'){
            if(cnt1 > cnt2){
                cnt2 = cnt1;
                sub2 = sub1;
            }
            cnt1 = 0, sub1 = "";
        } else {
            if(input[i] == '[')
                ++cnt1;
            sub1 += input[i];
        }
    }

    cout << cnt2 << "\n" << sub2 << "\n";
    return 0;
}
