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

    int n,k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = -1e9;
    for(int l = 0; l < n; ++l){ // O(n^3 logn)
        for(int r = l ; r < n; ++r){

            vector<int> v1, v2;
            for(int i = 0; i < n; ++i){
                if(l <= i && i <= r)
                    v1.push_back(a[i]);
                else
                    v2.push_back(a[i]);
            }

            sort(v1.begin(), v1.end());
            sort(v2.rbegin(), v2.rend());

            for(int i = 0; i < min(k, min((int)v1.size(), (int)v2.size())); ++i){
                if(v2[i] > v1[i])
                    v1[i] = v2[i];
                else
                    break;
            }

            int sum = 0;
            for(int i = 0; i < (int)v1.size(); ++i)
                sum += v1[i];

            ans = max(ans, sum);
        }
    }

    cout << ans << "\n";
    return 0;
}
