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

const int MAX = 9;
char board[MAX][MAX];
bool visited[MAX][MAX];
bool visByWhite[MAX][MAX];
bool visByBlack[MAX][MAX];

void readBoard(){
    for(int i = 0; i < MAX; ++i)
        for(int j = 0; j < MAX; ++j)
            cin >> board[i][j];
}

int cnt = 0;

bool validDir(int r, int c){
    return 0 <= r && r < MAX && 0 <= c && c < MAX;
}

void flood(int r, int c, char player){
    if(!validDir(r,c) || visited[r][c] || board[r][c] != player)
        return;

    ++cnt;
    visited[r][c] = true;

    flood(r-1, c, player);
    flood(r, c+1, player);
    flood(r+1, c, player);
    flood(r, c-1, player);
}

void floodByDot(int r, int c, char player){
    if(!validDir(r,c))
        return;
    if(board[r][c] == '.'){
        if(player == 'X'){
            if(visByBlack[r][c])
                return;
            else
                visByBlack[r][c] = true;
        }else{
            if(visByWhite[r][c])
                return;
            else
                visByWhite[r][c] = true;
        }
    }else{
        if(board[r][c] != player)
            cnt = -1;
        return;
    }

    if(cnt != -1)
        ++cnt;

    floodByDot(r-1, c, player);
    floodByDot(r, c+1, player);
    floodByDot(r+1, c, player);
    floodByDot(r, c-1, player);
}

int main(){
    fast_IO();


    int cases;
    cin >> cases;

    while(cases--){
        readBoard();

        memset(visited, 0, sizeof(visited));
        memset(visByWhite, 0, sizeof(visByWhite));
        memset(visByBlack, 0, sizeof(visByBlack));

        int white = 0, black = 0;
        for(int i = 0; i < MAX; ++i){
            for(int j = 0; j < MAX; ++j){
                cnt = 0; // reset counter

                if(visited[i][j] || (visByBlack[i][j] && visByWhite[i][j]))
                    continue;

                if(board[i][j] == 'X'){
                    flood(i,j,'X');
                    black += cnt;
                }
                else if(board[i][j] == 'O'){
                    flood(i,j,'O');
                    white += cnt;
                }
                else{
                    floodByDot(i,j,'X');
                    if(cnt != -1)
                        black += cnt;

                    cnt = 0;
                    floodByDot(i,j,'O');
                    if(cnt != -1)
                        white += cnt;
                }
            }
        }
        cout << "Black " << black << " White " << white << "\n";
    }

    return 0;
}
