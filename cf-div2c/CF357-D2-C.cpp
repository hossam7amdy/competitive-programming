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


int main(){
    fast_IO();

    int n,m;
    cin >> n >> m;

    set<int> alive;
    for(int i = 0; i < n; ++i)
        alive.insert(i);

    vector<int> ans(n, 0);
    for(int i = 0; i < m; ++i){ // O(mlogn)
        int l,r,x;
        cin >> l >> r >> x;
        --l, --r, --x;

        auto it = alive.lower_bound(l); // log(n)

        while(it != alive.end()){
            int cur = *it;

            if(cur > r)
                break;

            if(cur != x){
                ans[cur] = x+1;
                alive.erase(it++); // log(n)
            }
            else
                ++it;
        }
    }

    for(auto knight : ans)
        cout << knight << " ";

    return 0;
}
