#include <bits/stdc++.h>
using namespace std;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/*
0 0 0 0 0 0 0
1 1 1 0 0 0 0
1 0 0 0 0 0 0
0 0 0 1 1 0 0
0 0 0 0 0 1 1
0 0 1 0 0 0 0
0 0 0 1 0 0 1
1 0 0 0 0 0 0
*/
const int MAX = 100 + 1;
int grid[MAX][MAX];
int vis[MAX][MAX];
int n,m;

void dfs(int r, int c){
    if(vis[r][c] || !grid[r][c])
        return;

    vis[r][c] = 1;
    for(int j = 0; j <= m; ++j)
        if(grid[r][j] && !vis[r][j])
            dfs(r, j);

    for(int i = 0; i <= n; ++i)
        if(grid[i][c] && !vis[i][c])
            dfs(i, c);
}

int main(){
    fast_IO();

    memset(grid,0,sizeof(grid));
    memset(vis,0,sizeof(vis));

    int ans = 0;
    cin >> n >> m;
    for(int r = 1; r <= n; ++r){
        int langs;
        cin >> langs;
        ans += !langs; // he must learn one
        while(langs--){
            int c;
            cin >> c;
            grid[r][c] = 1;
        }
    }

    // How many connected components?
    int cnt = 0;
    for(int r = 1; r <= n; ++r)
        for(int c = 1; c <= m; ++c)
            if(grid[r][c] && !vis[r][c]){
                dfs(r,c);
                ++cnt;
            }
    if(cnt) --cnt;
    cout << ans + cnt << "\n";
    return 0;
}
