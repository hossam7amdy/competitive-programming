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

// ====================================
string actions[] {"fill A", "fill B", "empty A", "empty B", "pour A B", "pour B A", "Start"};
enum List        { FILL_A ,  FILL_B ,  EMPTY_A , EMPTY_B ,   POUR_A_B ,  POUR_B_A  , Start};

struct State { int a, b, action; };

const int MAX = 1000+9;

bool visited[MAX][MAX];
State prev_state[MAX][MAX];
queue<State> ready;

int ca, cb, N;

void backtrace(State cur){
    if(cur.a == 0 && cur.b == 0)
        return;

    backtrace(prev_state[cur.a][cur.b]);
    cout << actions[cur.action] << "\n";
}

void add_state(int a, int b, int action, State parent){
    if(visited[a][b])
        return;

    State cur = {a,b,action};
    ready.push(cur);
    prev_state[a][b] = parent;
    visited[a][b] = true;
}

void BFS(int a, int b){

    ready = queue<State>();
    memset(visited, 0, sizeof(visited));

    add_state(0, 0, Start, State());

    while(!ready.empty()){
        State cur = ready.front();
        ready.pop();

        int a = cur.a, b = cur.b, aa, bb;

        if(b == N){
            backtrace(cur);
            cout << "success\n";
            return;
        }

		add_state(a, cb, FILL_B, cur);
		add_state(ca, b, FILL_A, cur);
		add_state(a, 0, EMPTY_B, cur);
		add_state(0, b, EMPTY_A, cur);

		aa = (a+b)>ca ? ca:a+b;
		bb = (a+b)>ca ? (a+b)-ca:0;
		add_state(aa, bb, POUR_B_A, cur);

		aa = (a+b)>cb ? (a+b)-cb:0;
		bb = (a+b)>cb ? cb:a+b;
		add_state(aa, bb, POUR_A_B, cur);
    }
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("test.txt", "rt", stdin);
#endif

    while(cin >> ca >> cb >> N)
        BFS(0, 0);

    return 0;
}
