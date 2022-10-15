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

    const int MAX = 100005;
    vector<int> x(MAX, -2), pos(MAX, -2);
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        int idx;
        cin >> idx;

        if(pos[idx]==-2){
            x[idx] = 0;
            pos[idx] = i;
        }
        else if(x[idx] != -1){
            if(x[idx] == 0){
                x[idx] = i - pos[idx];
                pos[idx] = i;
            }
            else if((i- pos[idx]) != x[idx])
                x[idx] = -1;
            else
                pos[idx] = i;
        }
    }

    int sz = 0;
    for(int i=1; i<MAX; i++) // lazy handling :)
        if(x[i] >= 0)
            sz++;

    cout << sz << endl;
    for(int i=1; i<MAX; i++)
        if(x[i] >= 0)
            cout << i << " " << x[i] << "\n";

	return 0;
}
