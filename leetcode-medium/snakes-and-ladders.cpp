// https://leetcode.com/problems/snakes-and-ladders/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: BFS

#Complexity
    - Time O(n^2)
    - Space O(n^2)
*/

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    queue<int> ready;
    vector<bool> vis(n*n,0);

    for(int i = n - 2; i >= 0; i-=2)
        reverse(board[i].begin(), board[i].end());

    vis[0] = 1;
    ready.push(0);
    int level = 0;

    while(!ready.empty()){
        for(int sz = ready.size(); sz; --sz){
            int cur = ready.front(); ready.pop();

            if(cur == n * n - 1)
                return level;

            for(int st = cur + 1; st <= min(cur+6, n*n-1); ++st){
                int r = n - (st / n) - 1;
                int c = st % n;
                int next{};

                if(board[r][c] != -1)
                    next = board[r][c] - 1;
                else
                    next = st;

                if(vis[next]) continue;

                vis[next] = 1;
                ready.push(next);
            }
        }
        ++level;
    }

    return -1;
}

int main(){

    return 0;
}
