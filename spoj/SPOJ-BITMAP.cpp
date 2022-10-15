#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<char>> CHAR;
typedef vector<vector<int>> INT;

struct cell{
    int r, c;
};

void readGraph(CHAR &graph, int n, int m){
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> graph[i][j];
}

bool validDir(const CHAR &graph, int r, int c, int n, int m){
    return 0 <= r && r < n && 0 <= c && c < m && graph[r][c] != '1';
}

void shortestPath(const CHAR &graph, INT &result, int n, int m){
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};

    queue<cell> ready;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            if(graph[i][j] == '1')
                ready.push({i,j});

    for(int sz = (int)ready.size(), level = 1; !ready.empty(); sz = (int)ready.size(), ++level){
        while(sz--){
            cell cur = ready.front();
            ready.pop();

            for(int d = 0; d < 4; ++d){
                int nr = cur.r + dr[d], nc = cur.c + dc[d];

                if(!validDir(graph, nr, nc, n, m))
                    continue;

                if(result[nr][nc] == 0 || result[nr][nc] > level){
                    ready.push({nr,nc});
                    result[nr][nc] = level;
                }
            }
        }
    }
}

void printGraph(const auto &graph){
    for(auto row : graph){
        for(auto val : row)
            cout << val << " ";
        cout << "\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        CHAR graph(n, vector<char>(m));
        readGraph(graph, n, m);

        INT result(n, vector<int>(m, 0));
        shortestPath(graph, result, n, m);
        printGraph(result);
    }

    return 0;
}
