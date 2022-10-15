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

    int n,m;
    cin >> n >> m;

    int mnRange = n;
    while(m--){
        int l,r;
        cin >> l >> r;
        mnRange = min(mnRange, r-l+1);
    }

    cout << mnRange << "\n";
    for(int i = 0; i < n; ++i)
         cout << i % mnRange << " ";

    return 0;
}
