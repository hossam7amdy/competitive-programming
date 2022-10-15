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

ll N,M;

bool can(const ll &x, const ll &y){
    return 0 < x && x <= N && 0 < y && y <= M;
}
ll max_steps(const CELL &start, const CELL &dir){
    ll st = 1, en = max(N,M);

    ll steps = 0;
    while(st <= en){
        ll mid = st + (en - st) / 2;

        if(can(start.x + mid * dir.x, start.y + mid * dir.y))
            st = mid + 1, steps = mid;
        else
            en = mid - 1;
    }

    return steps;
}

int main(){
    fast_IO();
    cin >> N >> M;

    ll x,y;
    cin >> x >> y;

    int k;
    cin >> k;
    ll ans = 0;
    while(k--){ // O(klogn)
        ll dx, dy;
        cin >> dx >> dy;

        ll steps = max_steps({x,y}, {dx,dy});
        x += dx * steps;
        y += dy * steps;
        ans += steps;
    }

    cout << ans;

    return 0;
}
