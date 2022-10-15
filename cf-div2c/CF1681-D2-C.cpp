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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < n; ++i)
            cin >> b[i];

        bool flag = false;
        vector<CELL> ans;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n - 1; ++j){
                if(a[j] >= a[j + 1] && b[j] >= b[j + 1]){
                    swap(a[j], a[j + 1]);
                    swap(b[j], b[j + 1]);
                    ans.push_back({j + 1, j + 2});
                }else if(a[j] <= a[j + 1] && b[j] <= b[j + 1])
                    continue;
                else{
                    flag = true;
                    break;
                }
            }
        }

        if(flag){
            cout << "-1\n";
            continue;
        }

        cout << (int)ans.size() << "\n";
        for(CELL p : ans)
            cout << p.x << " " << p.y << "\n";
    }

    return 0;
}
