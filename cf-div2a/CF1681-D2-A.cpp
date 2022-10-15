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
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];

        int m;
        cin >> m;
        vector<int> b(m);
        for(int i = 0; i < m; ++i)
            cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        bool alice = false;
        auto start = b.begin();
        for(int i = n - 1; i >= 0; --i){
            auto it = upper_bound(start, b.end(), a[i]);

            if(it == b.end()){
                alice = true;
                break;
            }
            start = it;
        }
        alice ? cout << "Alice\n" : cout << "Bob\n";

        bool bob = false;
        start = a.begin();
        for(int i = m - 1; i >= 0; --i){
            auto it = upper_bound(start, a.end(), b[i]);

            if(it == a.end()){
                bob = true;
                break;
            }

            start = it;
        }

        bob ? cout << "Bob\n" : cout << "Alice\n";
    }

    return 0;
}
