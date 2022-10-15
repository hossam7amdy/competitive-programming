#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> GRAPH;
typedef pair<int,int> cell;
#define r first
#define c second
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

void addUndirectedEdge(GRAPH &graph, const int &from, const int &to){
    graph[from].push_back(to);
    graph[to].push_back(from);
}

enum COLOR { white, black };

bool canBeBlack(const GRAPH &graph, const vector<COLOR> &curCol, int node){
    for(int neighbor : graph[node])
        if(node == neighbor || curCol[neighbor] == black)
            return false;
    return true;
}

vector<int> bestBlack, curBlack;
void coloring(const GRAPH &graph, vector<COLOR> &curCol, int node){
    if(node == (int)curCol.size()){
        if((int)bestBlack.size() < (int)curBlack.size())
            bestBlack = curBlack;

        return;
    }

    if(canBeBlack(graph, curCol, node)){
        curCol[node] = black;
        curBlack.push_back(node);

        coloring(graph, curCol, node + 1);

        curBlack.pop_back();
        curCol[node] = white;
    }

    coloring(graph, curCol, node + 1);
}


int main(){
    fast();
    //readFile();

    int t;
    cin >> t;
    while(t--){
        int nodes, edges;
        cin >> nodes >> edges;
        GRAPH graph(nodes);
        for(int i = 0; i < edges; ++i){
            int from, to;
            cin >> from >> to;
            addUndirectedEdge(graph, from - 1, to - 1);
        }

        curBlack.clear();
        bestBlack.clear();
        vector<COLOR> curCol(nodes, white);
        coloring(graph, curCol, 0);

        int total = (int)bestBlack.size();
        cout << total << "\n";
        string space = "";
        for(int idx : bestBlack)
            cout << space << idx + 1, space = " ";
        cout << "\n";
    }

    return 0;
}
