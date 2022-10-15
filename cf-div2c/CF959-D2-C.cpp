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

    int n, root = 1;
    cin >> n;

    if(n < 6)
        cout << "-1\n";
    else{
        int child = 2;
        for(;child <= 4; ++child)
            cout << root << " " << child << "\n";
        for(;child <= n; ++child)
            cout << root + 1 << " " << child << "\n";
    }

    for(int child = 2; child <= n; ++child)
        cout << root << " " << child << "\n";

    return 0;
}
