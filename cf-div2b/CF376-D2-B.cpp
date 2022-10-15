#include<iostream>
#include <bits/stdc++.h>
using namespace std;

void PLAY() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << fixed << setprecision(4);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main(){
    //PLAY();

    int n,m,total_tebts = 0;
    cin >> n >> m;

    vector<int> debts(n+1), owes(n+1);

    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        owes[a] += c;
        debts[b] += c;
    }

    for(int i=1; i<=n; i++)
        if(owes[i]>debts[i])
            total_tebts += owes[i] - debts[i];

    cout << total_tebts;

	return 0;
}
