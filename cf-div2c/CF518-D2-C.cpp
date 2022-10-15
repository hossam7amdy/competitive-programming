#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define ll long long
#define X first
#define Y second
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main(){
    fast();

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> positions(500001, -1), applications(n);

    for(int i = 0; i < n; ++i){
        cin >> applications[i];
        positions[applications[i]] = i;
    }

    ll ans = 0;
    while(m--){
        int app;
        cin >> app;
        int pos = positions[app];
        ans += pos / k + 1;

        if(pos >= 1){
            swap(applications[pos], applications[pos-1]);
            --positions[app];
            ++positions[applications[pos]];
        }
    }

    cout << ans << "\n";

    return 0;
}
