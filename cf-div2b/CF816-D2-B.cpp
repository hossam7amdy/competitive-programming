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

    const int MAX {200005};
    int freq[MAX] = {0};

    int n,k,q;
    cin >> n >> k >> q;

    // 1) mark Intervals
    while(n--){
        int a,b;
        cin >> a >> b;
        freq[a]++;
        freq[b+1]--;
    }

    // 2) calculate frequencies
    for(int i = 1; i < MAX; ++i)
        freq[i] += freq[i-1];

    // 3) validate if(admissible)
    for(int i = 0; i < MAX; ++i)
        (freq[i] < k) ? freq[i] = 0 : freq[i] = 1;

    // 4) accumulate frequencies
    for(int i = 1; i < MAX; ++i)
        freq[i] += freq[i-1];


    // 5) answer queries
    while(q--){
        int a,b;
        cin >> a >> b;
        cout << freq[b] - freq[a-1] << "\n";
    }

    return 0;
}
