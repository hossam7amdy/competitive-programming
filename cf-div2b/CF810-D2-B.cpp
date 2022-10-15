#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

struct product {
    int x, x2, comp;

    bool operator < (const product &another) {
        return comp < another.comp;
    }
};


int main() {
    fast();

    int n,f;
    cin >> n >> f;

    vector<product> shop(n);
    for(int i = 0; i < n; ++i){
        int k,l;
        cin >> k >> l;

        shop[i].x = min(k, l);
        shop[i].x2 = min(2*k, l);
        shop[i].comp = shop[i].x2 - shop[i].x;
    }

    sort(shop.rbegin(), shop.rend()); // O(nlogn)

    ll res{};
    for(int i = 0; i < n; ++i){ // O(n)
        if(i < f)
            res += shop[i].x2;
        else
            res+= shop[i].x;
    }

    cout << res << endl;

    return 0;
}
