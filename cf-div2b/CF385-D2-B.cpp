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

    string input, sub = "bear";
    cin >> input;

    int pos = 0, idx = 0, res = 0;
    int sz = (int)input.size();

    while((pos = input.find(sub)) != -1){
        res += (sz - (pos + idx + 3));
        idx++;
        input = input.substr(1);

    }

    cout << res << endl;

	return 0;
}
