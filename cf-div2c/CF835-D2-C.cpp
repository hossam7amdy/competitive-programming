#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false), cin.tie(NULL);
#define cell pair<int,int>
#define x first
#define y second
#define ll long long

void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

const int N = 100 + 1;
const int C = 10 + 1;

int grid[N][N][C];

int main(){
    fast;

    int n,q,c;
    cin >> n >> q >> c;

    for(int i = 1; i <= n; ++i){
        int x,y,s;
        cin >> x >> y >> s;
        ++grid[x][y][s];
    }

    // accumulate rows
    for(int i = 1; i < N; ++i)
        for(int j = 1; j < N; ++j)
            for(int k = 0; k < C; ++k)
                grid[i][j][k] += grid[i-1][j][k];

    // accumulate cols
    for(int i = 1; i < N; ++i)
        for(int j = 1; j < N; ++j)
            for(int k = 0; k < C; ++k)
                grid[i][j][k] += grid[i][j-1][k];

    // answer queries
    for(int i = 0; i < q; i++){
        int ans = 0;
        int t,a,b,x,y;
        cin>> t >> a >> b >> x >> y;

        for(int k=0; k < C; k++){
            int cnt = grid[x][y][k] + grid[a-1][b-1][k] - grid[a-1][y][k] - grid[x][b-1][k];
            int pri = (k + t) % (c + 1);
            ans = ans + (pri * cnt);
        }
        cout << ans << "\n";
    }

    return 0;
}
