#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

ll possible(const vector<ll> &souvenirs, const ll &idx, const ll &budget){
    ll sz = (ll)souvenirs.size();
    vector<ll> new_prices(sz);
    for(ll i = 0; i < sz; ++i)
        new_prices[i] = souvenirs[i] + (i + 1) * idx;

    sort(new_prices.begin(), new_prices.end());

    ll canBuy = 0;
    for(ll i = 0; i < idx; ++i){
        canBuy += new_prices[i];

        if(budget < canBuy)
            return -1;
    }
    return canBuy;
}

pair<ll, ll> maxSouv(const vector<ll> &souvenirs, const ll &budget){
    ll st = 0, en = (ll)souvenirs.size();

    ll idx = 0, canBuy = 0;
    while(st <= en){

        ll mid = st + (en - st) / 2;
        ll total = possible(souvenirs, mid, budget);

        if(total != -1)
            st = mid + 1, idx = mid, canBuy = total;
        else
            en = mid - 1;
    }
    return {idx, canBuy};
}

int main(){
    ll n, budget;
    cin >> n >> budget;

    vector<ll> souvenirs(n);
    for(ll i = 0; i < n; ++i)
        cin >> souvenirs[i];

    pair<ll, ll> ans = maxSouv(souvenirs, budget);
    cout << ans.first << " " << ans.second << "\n";

    return 0;
}
