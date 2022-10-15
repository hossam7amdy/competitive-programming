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
        double sum = 0;
        cin >> n;

        vector<double> v(n);
        for(int i = 0; i < n; ++i){
            cin >> v[i];
            sum += v[i];
        }

        bool flag = false;
        for(int i = 0; i < n; ++i){
            double cur_avg = (sum - v[i]) / (n - 1);
            if(cur_avg == v[i]){
                flag = true;
                break;
            }
        }

        flag ? cout << "Yes" : cout << "No";
        cout << "\n";
    }

    return 0;
}
