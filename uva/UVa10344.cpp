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

void backtrack(const vector<int> &values, vector<int> &visited, bool &found, int sum, int len, bool first = false){
    if(found)
        return;

    if(len == (int)values.size()){
        found |= (sum == 23);
        return;
    }

    for(int i = 0; i < 5; ++i){
        if(visited[i]) continue;

        // do
        visited[i] = true;

        // recurse
        if(first){
            backtrack(values, visited, found, sum + values[i], len + 1, true);
            backtrack(values, visited, found, sum - values[i], len + 1, true);
            backtrack(values, visited, found, sum * values[i], len + 1, true);
        }else
            backtrack(values, visited, found, values[i], len + 1, true);

        // undo
        visited[i] = false;
    }
}

int main(){
    fast();
    //readFile();
    const int n = 5;
    while(true){
        int sum = 0;
        vector<int> values(n), visited(n);
        for(int i = 0; i < n; ++i){
            cin >> values[i];
            sum += values[i];
        }
        if(!sum)
            return 0;
        bool found = false;
        backtrack(values, visited, found, 0, 0);

        if(found)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}
