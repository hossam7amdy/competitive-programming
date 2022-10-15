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

    ll n, a = 1, b = 1, mod = 1e9 + 7;
    cin >> n;

    // ans = 3 ^ (3 * n)
    // ans = ans - (7 ^ n)

    for(int i = 1; i <= n * 3; ++i)
        a = (a * 3) % mod;

    for(int i = 1; i <= n; ++i)
        b = (b * 7) % mod;

    cout << (a - b + mod) % mod;
    return 0;
}
