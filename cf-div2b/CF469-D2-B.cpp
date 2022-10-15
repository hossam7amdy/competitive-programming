#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define X first
#define Y second
#define ll long long

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}


int main(){
    fast_IO();

    int p,q,l,r;
    cin >> p >> q >> l >> r;

    vector<CELL> p1;
    while(p--){
        int a,b;
        cin >> a >> b;
        p1.push_back({a,b});
    }

    int cnt = 0;
    vector<bool> vis(r+1, 0);
    while(q--){
        int c,d;
        cin >> c >> d;

        for(int j = 0; j < (int)p1.size(); ++j){
            for(int i = l; i <= r; ++i){
                if(vis[i] || p1[j].Y < c + i || p1[j].X > d + i)
                    continue;

                vis[i] = 1;
                ++cnt;
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
