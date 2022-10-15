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

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> deck(n);
        for(int i = 0; i < n; ++i)
            cin >> deck[i];

        int m, top = 0;
        cin >> m;
        while(m--){
            int idx;
            cin >> idx;

            top += idx;
            top %= n;
        }

        cout << deck[top] << "\n";
    }


    return 0;
}
