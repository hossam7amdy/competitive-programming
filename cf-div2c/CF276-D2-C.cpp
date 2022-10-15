#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fast_IO();

    int n,q;
    cin >> n >> q;

    vector<ll> nums(n), freq(n + 1, 0);
    for(int i = 0; i < n; ++i)
        cin >> nums[i];

    for(int i = 0; i < q; ++i){
        int l,r;
        cin >> l >> r;
        freq[l-1]++, freq[r]--;
    }

    for(int i = 1; i < n; ++i)
        freq[i] += freq[i-1];

    sort(nums.rbegin(), nums.rend());
    sort(freq.rbegin(), freq.rend());

    ll ans = 0;
    for(int i = 0; i < n; ++i)
        ans += (nums[i] * freq[i]);

    cout << ans << "\n";

    return 0;
}
