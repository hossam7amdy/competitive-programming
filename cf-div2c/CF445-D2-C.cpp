#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
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

    int n, m;
    cin >> n >> m;
    vector<int> nodes(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> nodes[i];

    double ans = 0;
    for(int i = 1; i <= m; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        ans = max(ans, 1.0 * (nodes[a] + nodes[b]) / c);
    }

    cout << fixed << showpoint;
    cout << setprecision(15);
    cout << ans << "\n";

    return 0;
}
