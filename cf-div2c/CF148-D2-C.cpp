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

    int n, a, b;
    cin >> n >> a >> b;

    int ans = 1;
    if(a + b == 0){
        for(int i = 0; i < n; ++i)
            cout << ans << " ";
        return 0;
    }
    if(a && a >= n - 1){
        cout <<  "-1";
        return 0;
    }

    int idx = 1;
    cout << ans << " ";
    for(int i = 0; i < b; ++i, ++idx){
        ans *= 2;
        cout << ans << " ";
    }

    for(int i = 0; i < a; ++i, ++idx){
        if(b)
            cout << ++ans << " ";
        else
            cout << ans++ << " ";
    }

    for(;idx < n; ++idx)
        cout << ans << " ";

    return 0;
}
