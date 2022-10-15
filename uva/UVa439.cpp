#include<bits/stdc++.h>
using namespace std;

/// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380

const int MAX = 8;
bool board[MAX][MAX];

int dRow[MAX] {-2,-2,-1,1,2,2,1,-1};
int dCol[MAX] {-1,1,2,2,1,-1,-2,-2};

bool isValid(int r, int c){
    return (0<=r && r<MAX && 0<=c && c<MAX);
}

int BFS(const pair<int, int>& s, const pair<int, int>& d){

    queue< pair<int,int> > q;
    q.push(s);

    board[s.first][s.second] = true;

    int steps = 1, sz = 1;
    for(;!q.empty();++steps, sz = q.size()){
        while(sz--){

            pair<int,int> curr = q.front();
            q.pop();

            for(int k=0; k<MAX; ++k){
                int nr = curr.first + dRow[k];
                int nc = curr.second + dCol[k];

                if(isValid(nr,nc) && board[nr][nc]==0){
                    q.push(make_pair(nr,nc));
                    board[nr][nc] = true;

                    if(nr==d.first && nc==d.second)
                        return steps;
                }
            }
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    string line;
    while(getline(cin,line)){

        memset(board, false, sizeof(board));

        pair<int, int> s,d;
        s = make_pair(line[1]-'1',line[0]-'a');
        d = make_pair(line[4]-'1',line[3]-'a');

        int moves = 0;
        if(s==d){
            cout << "To get from " << line[0] << line[1] << " to " << line[3] << line[4] << " takes " << moves << " knight moves.\n";
            continue;
        }
        moves = BFS(s,d);
        cout << "To get from " << line[0] << line[1] << " to " << line[3] << line[4] << " takes " << moves << " knight moves.\n";
    }

    return 0;
}
