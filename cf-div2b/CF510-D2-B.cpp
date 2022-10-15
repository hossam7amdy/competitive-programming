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

int n,m;
bool cycle = false;
char board[55][55];
bool visited[55][55];

int dr[] {-1,0,1,0};
int dc[] {0,1,0,-1};
void dfs(CELL st, CELL prev, char cur_letter){
    if(visited[st.x][st.y]){
        cycle = true;
        return;
    }

    visited[st.x][st.y] = true;
    for(int d = 0; d < 4; ++d){
        int nr = st.x + dr[d];
        int nc = st.y + dc[d];
        if(0 <= nr && nr < n && 0 <= nc && nc < m && CELL(nr, nc) != prev && board[nr][nc] == cur_letter)
            dfs({nr,nc}, st, cur_letter);
    }
}


int main(){
    fast_IO();

    cin >>  n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> board[i][j];

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!visited[i][j]){
                dfs({i,j}, {i,j}, board[i][j]);
                if(cycle){
                    cout << "Yes\n";
                    return 0;
                }
            }
        }
    }

    cout << "No\n";
    return 0;
}
