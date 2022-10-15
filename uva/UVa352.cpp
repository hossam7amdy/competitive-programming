#include<bits/stdc++.h>
using namespace std;

void Run(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
}

const int MAX = 25;
char grid[MAX][MAX];
bool vis[MAX][MAX];
int sz;

bool isValid(const int &nr, const int &nc){
    if(0>nr || nr>=sz || 0>nc || nc>=sz)
        return false;

    if(grid[nr][nc]=='0')
        return false;

    return !vis[nr][nc];
}

void DFS(const int &r, const int &c){
    if(!isValid(r,c))
        return;

    vis[r][c] = true;

    DFS(r+1,c);
    DFS(r-1,c);
    DFS(r,c+1);
    DFS(r,c-1);
    DFS(r+1,c+1);
    DFS(r-1,c-1);
    DFS(r+1,c-1);
    DFS(r-1,c+1);
}

int main(){
    Run();

    int image = 1;
    while(cin >> sz){
        int c = 0;
        memset(vis, 0, sizeof(vis));

        for(int i=0; i<sz; i++)
            cin >> grid[i];

        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    DFS(i,j);
                    c++;
                }
            }
        }

        cout << "Image number " << image++ << " contains " << c  << " war eagles.\n";
    }

    return 0;
}
