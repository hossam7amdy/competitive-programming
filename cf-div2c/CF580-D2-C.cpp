#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

typedef vector<vector<int>> GRAPH;
void addEdge(GRAPH &adjList, int from, int to){
    adjList[from].push_back(to);
    adjList[to].push_back(from);
}

void dfs(const GRAPH &adjList, int node, vector<int> &weight, const int &m, vector<bool> &vis, int &k){
    vis[node] = true;
    for(auto neighbor : adjList[node]){
        if(!vis[neighbor]){
            if(weight[neighbor])
                weight[neighbor] += weight[node];
            if(weight[neighbor] <= m)
                dfs(adjList, neighbor, weight, m, vis, k);
        }else{
            if((int)adjList[node].size() == 1) // leave
                if(weight[node] <= m)
                    ++k;
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    GRAPH adjList(n);
    vector<int> weight(n);
    vector<bool> vis(n);

    for(int i = 0; i < n; ++i)
        cin >> weight[i];

    for(int i = 0; i < n - 1; ++i){
        int from, to;
        cin >> from >> to;
        addEdge(adjList, from - 1, to - 1);
    }

    if(adjList[0].empty()){
        cout << "0\n";
        return 0;
    }

    int cnt = 0;
    dfs(adjList, 0, weight, m, vis, cnt);
    cout << cnt << "\n";

    return 0;
}
