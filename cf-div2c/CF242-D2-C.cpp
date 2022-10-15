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
    freopen("output.txt", "w", stdout);
}

set<CELL> path;
int king_path(CELL source, CELL dist){
    int dr[] = {-1,-1,-1,0,1,1,1,0};
    int dc[] = {-1,0,1,1,1,0,-1,-1};

    set<CELL> vis;
    queue<CELL> ready;

    ready.push(source);
    vis.insert(source);

    for(int level = 1, sz = (int)ready.size(); !ready.empty(); sz = (int)ready.size(), ++level){
        while(sz--){
            CELL cur = ready.front();
            ready.pop();

            for(int d = 0; d < 8; ++d){
                int nr = cur.X + dr[d];
                int nc = cur.Y + dc[d];

                if(!path.count({nr,nc}) || vis.count({nr,nc}))
                    continue;

                if(CELL(nr,nc) == dist)
                    return level;

                ready.push({nr,nc});
                vis.insert({nr,nc});
            }
        }
    }

    return -1;
}

int main(){
    fast();

    CELL s,d;
    cin >> s.X >> s.Y >> d.X >> d.Y;

    int n;
    cin >> n;
    while(n--){
        int r,a,b;
        cin >> r >> a >> b;

        while(a <= b)
            path.insert({r,a++});
    }

    cout << king_path(s,d) << endl; // O(nlogn)

    return 0;
}
