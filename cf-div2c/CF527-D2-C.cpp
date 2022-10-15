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

    int w,h,n;
    cin >> w >> h >> n;

    set<int> vert, horz;
    horz.insert(0), horz.insert(h);
    vert.insert(0), vert.insert(w);

    map<ll,int> best_h, best_v;
    best_h[h]++, best_v[w]++;

    while(n--){ // O(nlogn)
        char ch;
        int cur;
        cin >> ch >> cur;

        if(ch == 'H'){
            auto prev = horz.lower_bound(cur);
            auto next = prev;
            --prev;

            horz.insert(cur);

            if(--best_h[*next - *prev] == 0)
                best_h.erase(*next - *prev);

            best_h[*next - cur]++;
            best_h[cur - *prev]++;
        }
        else{
            auto prev = vert.lower_bound(cur);
            auto next = prev;
            --prev;

            vert.insert(cur);

            if(--best_v[*next - *prev] == 0)
                best_v.erase(*next - *prev);

            best_v[*next - cur]++;
            best_v[cur - *prev]++;
        }
        cout << best_h.rbegin()->first * best_v.rbegin()->first << "\n";
    }

    return 0;
}
