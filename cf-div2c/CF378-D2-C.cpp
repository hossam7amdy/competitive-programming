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
    //freopen("output.txt", "w", stdout);
}

bool validDir(const vector<string> &grid, const int &r, const int &c){
    return 0 <= r && r < (int)grid.size() && 0 <= c && c < (int)grid[r].size() && grid[r][c] != '#';
}

int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int counter;
void dfs(const vector<string> &grid, vector<vector<bool>> &visited, const CELL &cell){
    if(counter == 0)
        return;

    for(int d = 0; d < 4; ++d){
        int nr = cell.X + dr[d];
        int nc = cell.Y + dc[d];
        if(validDir(grid, nr, nc) && !visited[nr][nc] && counter > 0){
            --counter;
            visited[nr][nc] = true;
            dfs(grid, visited, {nr, nc});
        }
    }
}

int main(){
    fast();

    int n,m,k,s=0;
    cin >> n >> m >> k;
    vector<string> maze(n);
    for(int i = 0; i < n; ++i)
        cin >> maze[i];

    CELL start = {-1,-1};
    for(int r = 0; r < n; ++r){
        for(int c = 0; c < m; ++c){
            if(maze[r][c] == '.'){
                if(start.X == -1)
                    start = {r,c};
                ++s;
            }
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m,false));
    counter = s - k;
    --counter;
    visited[start.X][start.Y] = true;
    dfs(maze, visited, start); // flood fill (s - k) times
    for(int r = 0; r < n; ++r)
        for(int c = 0; c < m; ++c)
            if(maze[r][c] == '.' && !visited[r][c])
                maze[r][c] = 'X';

    for(int i = 0; i < n; ++i)
        cout << maze[i] << "\n";

    return 0;
}
