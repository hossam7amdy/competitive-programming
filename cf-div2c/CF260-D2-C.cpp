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

ll arr[100000 + 1];

int main(){
    fast_IO();

    ll n,x;
    cin >> n >> x;
    --x; // 0-based

    ll minVal = 1e9;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        minVal = min(minVal, arr[i]);
    }

    ll ans = minVal * n;
    for(int i = 0; i < n; ++i)
        arr[i] -= minVal;

    while(arr[x]){ // x must be zero
        --arr[x];
        ++ans;

        x = (x - 1 + n) % n; // move backward
    }

    arr[x] = ans;
    for(int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    return 0;
}
