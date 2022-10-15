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

    int n, k;
    cin >> n >> k;

    int input, mini = INT_MAX;
    long long int sum = 0;
    while(n--){
        cin >> input;
        if(k && input<0){
            input = -input;
            k--;
        }
        mini = min(mini, input);
        sum += input;
    }

    if(k%2==1)
        sum -= (2*mini);

    cout << sum << endl;

	return 0;
}
