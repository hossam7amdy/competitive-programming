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

    string str;
    cin >> str;

    int n = (int)str.size();
    vector<int> freq(n, 0);

    int m;
    cin >> m;
    while(m--){
        int idx;
        cin >> idx;

        freq[idx-1]++;
    }

    int accum = 0;
    for(int i = 0; i < n/2; ++i){
        accum += freq[i];
        if(accum % 2 != 0)
            swap(str[i], str[n-i-1]);
    }

    cout << str << "\n";
    return 0;
}
