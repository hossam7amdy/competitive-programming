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


bool is_valid(const vector<int> &v){
    for(int i = 1; i < (int)v.size() - 1; i+=2)
        if(v[i - 1] >= v[i] || v[i] <= v[i + 1])
            return false;

    return true;
}

int main(){
    fast_IO();

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
            cin >> v[i];

        if(n % 2 == 1){
            cout << "NO\n";
            continue;
        }
        sort(v.begin(), v.end());

        vector<int> ans(n);
        int st = 0, mid = n / 2;
        for(int i = 0; i < n; i+=2){
            ans[i] = v[st++];
            ans[i+1] = v[mid++];
        }

        if(!is_valid(ans)){
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for(auto item : ans)
            cout << item << " ";

        cout << "\n";
    }

    return 0;
}
