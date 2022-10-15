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

int upper(const vector<int> &v, int st, int val){
    int en = (int)v.size() - 1;

    int res = -1;
    while(st <= en){
        int mid = st + (en - st) / 2;
        if(v[mid] <= val)
            st = mid + 1, res = mid;
        else
            en = mid - 1;
    }
    return res;
}

int main(){
    fast_IO();
    readFile();

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int mx_window = 0;
    for(int i = 0; i < n; i++){
        int idx = upper(v, i, 2*v[i]);
        int cur_window = idx - i + 1;
        mx_window = max(mx_window, cur_window);
    }

    cout << n - mx_window;

    return 0;
}
