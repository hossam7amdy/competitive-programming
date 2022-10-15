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


int main(){
    fast();

    int n,m,ans=0;
    cin >> n >> m;

    vector<bool> vis(m+1, 0);
    for(int i=0; i<n; i++){ // O(nm)
        char ch;
        int g, s;
        for(int j=0; j<m; j++){
            cin >> ch;
            if(ch == 'G')
                g = j;
            else if(ch == 'S')
                s = j;
        }
        if(g>s){
            cout << "-1";
            return 0;
        }
        if(!vis[s-g]){
            vis[s-g] = 1;
            ++ans;
        }
    }

    cout << ans;

    return 0;
}
