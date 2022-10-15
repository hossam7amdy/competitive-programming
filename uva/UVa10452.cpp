#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int const MAX = 8;
vector<string> lines;
int m,n;
char grid[MAX][MAX];
string path{"IEHOVA#"};

int dr[]{-1,0,0};
int dc[]{0,-1,1};
string output[] {"forth","left","right"};

bool valid(int nr, int nc){ return 0<=nr && 0<=nc && nr<m && nc<n; }

void dfs(int r, int c, int idx=0){
    if(idx>grid[r][c]) return;

    for(int i=0; i<3; i++){
        int nr = dr[i] + r;
        int nc = dc[i] + c;
        if(valid(nr,nc) && grid[nr][nc]==path[idx]){
            lines.push_back(output[i]);
            dfs(nr,nc,idx+1);
        }
    }
}

int main(){

    int sample;
    cin >> sample;
    while(sample--){
        lines.clear(); // clear the vector with each case

        cin >> m >> n;
        for(int i=0; i<m; i++){
            cin >> grid[i];
            for(int j=0; j<n; j++){
                if(grid[i][j]=='@')
                    dfs(i,j);
            }
        }
        cout << lines[0];
        for(int i=1; i<(int)lines.size(); i++)
            cout << " " << lines[i];
        cout << endl;
    }

    return 0;
}
