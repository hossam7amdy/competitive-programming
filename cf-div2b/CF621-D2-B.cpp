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

    int n;
    cin >> n;


    int mp1[2005]{0};
    int mp2[2005]{0};

    int ans = 0;
    for(int i = 0; i < n; ++i){
        int x,y;
        cin >> x >> y;

        // ans += (x * (x-1)) / 2
        ans += mp1[x+y];
        mp1[x+y]++;

        ans += mp2[x-y+1000];
        mp2[x-y+1000]++;
    }

    cout << ans << "\n";
    return 0;
}
