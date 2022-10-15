#include<iostream>
using namespace std;

/// https://codeforces.com/contest/287/problem/A

int main(){
    char grid[4][4];
    int dr[] = {0,1,1};
    int dc[] = {1,0,1};

    for(int i=0; i<4; i++)
        cin >> grid[i];

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int cnt = 0;
            cnt += (grid[i][j]=='#');
            for(int k=0; k<3; k++){
                int nr = dr[k] + i;
                int nc = dc[k] + j;
                cnt += (grid[nr][nc]=='#');
                }
            if(cnt!=2){
                cout << "YES";
                return 0;
                }
            }
        }

    cout << "NO";

    return 0;
}
