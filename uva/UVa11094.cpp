#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int ROWS, COLS, regions_cnt = 0;
char land;

char matrix[20][20];
bool is_visited[20][20];

bool is_valid(const int &r, const int &c){
    if(is_visited[r][c] || matrix[r][c] != land)
        return false;

    return 0<=r && r<ROWS && 0<=c && c<COLS;
}

int col_next(const int &c){
    if(c == COLS) return 0;
    if(c == -1) return COLS-1;
    return c;
}

void DFS(const int &r, const int &c){
    if(!is_valid(r,c))
        return;

    regions_cnt++;
    is_visited[r][c] = true;

    DFS(r, col_next(c-1));
    DFS(r, col_next(c+1));
    DFS(r-1,c);
    DFS(r+1,c);
}

int main(){
    PLAY();

    while(cin >> ROWS >> COLS){

        memset(is_visited, false, sizeof(is_visited));

        for(int i=0; i<ROWS; i++)
            cin >> matrix[i];

        int cur_R, cur_C;
        cin >> cur_R >> cur_C;
        land = matrix[cur_R][cur_C];
        DFS(cur_R, cur_C);

        int largest_continent = 0;
        for(int r=0; r<ROWS; r++)
            for(int c=0; c<COLS; c++)
                if(matrix[r][c]==land && !is_visited[r][c]){
                    regions_cnt=0;
                    DFS(r,c);
                    largest_continent = max(largest_continent, regions_cnt);
                }

        cout << largest_continent << "\n";
    }

	return 0;
}
