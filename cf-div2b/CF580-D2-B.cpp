#include<bits/stdc++.h>
using namespace std;


int main(){
    int n, d;
    cin >> n >> d;
    vector< pair<int, int> > v(n);

    for(int i=0; i<n; i++)
        cin >> v[i].first >> v[i].second;

    sort(v.begin(), v.end());

    int cur_pos = 0;
    long long int sum = 0, ans = 0;

    for(int i=0; i<n; i++){
        if(abs(v[i].first - v[cur_pos].first) >= d){
            while(abs(v[i].first - v[cur_pos].first) >= d)
                sum -= v[cur_pos++].second;
        }
        sum += v[i].second;
        ans = max(sum, ans);
    }

    cout << ans << endl;

    return 0;
}
