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


set<CELL> vis;
queue<CELL> ready;
int A,B,C;

void pour(int a, int b){
    CELL cur = {a,b};
    if(vis.count(cur))
        return;

    vis.insert(cur);
    ready.push(cur);
}

int BFS(){
    ready = queue<CELL>();
    vis.clear();

    ready.push({0,0});
    vis.insert({0,0});

    int steps = 0;
    while(!ready.empty()){
        for(int sz = (int)ready.size(); sz; --sz){
            auto cur = ready.front();
            ready.pop();

            int aa = cur.x, bb = cur.y;
            if(aa == C || bb == C)
                return steps;

            // 1- fill(a)
            pour(A,bb);

            // 2- fill(b)
            pour(aa,B);

            // 3- empty(a)
            pour(0,bb);

            // 4- empty(b)
            pour(aa,0);

            // 5- pour(a,b)
            int newB = min (B, aa+bb);
            int newA = aa - (newB-bb);
            pour(newA,newB);

            // 6- pour(b,a)
            newA = min (A,aa+bb);
            newB = bb - (newA-aa);
            pour(newA,newB);
        }
        ++steps;
    }

    return -1;
}

int main(){
    fast_IO();

    int cases;
    cin >> cases;

    while(cases--){
        cin >> A >> B >> C;
        if(A < C && C > B)
            cout << "-1\n";
        else
            cout << BFS() << "\n";
    }
    return 0;
}
