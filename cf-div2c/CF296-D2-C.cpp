#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

/*

1- for each query compute freq
2- for each operation compute freq

---
EXAMPLE: - time O(n)

array
1 2 3 2

operations
1 2 1 => add 2
1 3 2 => add 6
2 3 4 => add 8
8 8 -2 -14 0
8 16 14 0 0

queries
1 2
1 3
2 3
2 1 -1 -2
2 3 2 0

answer
9 18 17 2

*/

struct op {
    int l,r;
    ll val;
};

int main(){
    fast_IO();

    int n,m,k;
    cin >> n >> m >> k;
    vector<ll> arr(n);
    vector<op> oper(m);

    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < m; ++i)
        cin >> oper[i].l >> oper[i].r >> oper[i].val;

    vector<int> freq_q(m + 1, 0);
    for(int i = 0; i < k; ++i){
        int x,y;
        cin >> x >> y;
        freq_q[x-1]++;
        freq_q[y]--;
    }
    for(int i = 1; i < m; ++i)
        freq_q[i] += freq_q[i-1];

    vector<ll> freq_op(n + 1, 0);
    for(int i = 0; i < m; ++i){
        freq_op[oper[i].l-1] += freq_q[i] * oper[i].val;
        freq_op[oper[i].r] -= freq_q[i] * oper[i].val;
    }
    for(int i = 1; i <= n; ++i){
        freq_op[i] += freq_op[i-1];
        cout << arr[i-1] + freq_op[i-1] << " ";
    }
    return 0;
}
