#include <bits/stdc++.h>
using namespace std;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

#define ll long long
vector<int> vertices, visited;
vector<vector<pair<int,ll>>> graph;

void addEdge(const int &from, const int &to, const int &cost){
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

int counter = 0;
void canReach(const int &start, ll path = 0, bool flag = false){
    visited[start] = 1;

    if(path > vertices[start])
        flag = true;

    if(flag)
        ++counter;

    for(auto neighbour : graph[start]){
        if(!visited[neighbour.first])
            canReach(neighbour.first, max(path+neighbour.second, neighbour.second), flag);
    }
}

int main(){
    fast();

    int n;
    cin >> n;

    graph.resize(n);
    vertices.resize(n);
    visited.resize(n, 0);

    for(int i = 0; i < n; ++i)
        cin >> vertices[i];

    for(int i = 1; i <= n - 1; ++i){
        int to, cost;
        cin >> to >> cost;
        addEdge(i, to - 1, cost);
    }

    canReach(0);
    cout << counter << "\n";



    return 0;
}
