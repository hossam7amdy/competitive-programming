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

int n;
vector<int> init, goal;
vector<vector<int>> graph;


vector<int> vis, ans;
void dfs(int start, bool flag, int oddCnt, int evenCnt){
    vis[start] = 1;

    if(flag){
        if((init[start] + oddCnt) % 2 != goal[start]){
            ++oddCnt;
            ans.push_back(start);
        }
    }else{
        if((init[start] + evenCnt) % 2 != goal[start]){
            ++evenCnt;
            ans.push_back(start);
        }
    }

    for(auto node : graph[start]){
        if(!vis[node])
            dfs(node, !flag, oddCnt, evenCnt);
    }
}

int main(){
    fast_IO();

    cin >> n;

    init.resize(n+1);
    goal.resize(n+1);
    graph.resize(n+1);

    for(int i = 1; i <= n - 1; ++i){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i = 1; i <= n; ++i)
        cin >> init[i];
    for(int i = 1; i <= n; ++i)
        cin >> goal[i];

    vis.resize(n+1, 0);
    dfs(1, true, 0 ,0);

    cout << (int)ans.size() << "\n";
    for(auto item : ans)
        cout << item << "\n";
    return 0;
}
