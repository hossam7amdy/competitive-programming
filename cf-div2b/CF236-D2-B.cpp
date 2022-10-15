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

vector<int> v(1000001, 0);
int divisors(const int &num){
    if(v[num]!=0)
        return v[num];

    int res = 0;
    for(int i=1; i*i<=num; i++){
        if(num%i==0){
            res++;
            if(i * i != num)
                res++;
        }
    }

    v[num] = res;
    return res;
}

int main(){
    //PLAY();

    int a,b,c, ans = 0, mod = 1073741824;
    cin >> a >> b >> c;


    for(int i=1; i<=a; i++)
        for(int j=1; j<=b; j++)
            for(int k=1; k<=c; k++)
                ans += divisors(i*j*k);

    cout << ans%mod;

	return 0;
}
