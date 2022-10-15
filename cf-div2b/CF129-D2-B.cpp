#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
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


int main(){
    fast();

    int n,m;
    cin >> n >> m;

    GRAPH graph(n+1);
    for(int i = 0; i < m; ++i){
        int from, to;
        cin >> from >> to;

        // Build graph
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int ans = 0;
    while(true){ // O(nm)
        vector<int> toKick;
        for(int i = 1; i <= n; ++i) // O(n)
            if((int)graph[i].size() == 1)
                toKick.push_back(i);

        if(toKick.empty())
            break;

        ++ans;
        for(auto st : toKick){
            int idx = graph[st].front();
            auto iter = find(graph[idx].begin(), graph[idx].end(), st);
            if(iter != graph[idx].end())
                graph[idx].erase(iter);
            graph[st].clear();
        }
    }

    cout << ans << endl;

    return 0;
}
