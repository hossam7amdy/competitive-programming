#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/// https://codeforces.com/contest/567/problem/A


int main(){
    vector<int> vec;
    int n, mn, mx;

    cin >> n;
    while(n--){
        cin >> mx;
        vec.push_back(mx);
        mx = 0;
    }

    int sz = vec.size();
    for(int i=0; i<sz; i++){
        if(!i)
            mn = vec[i+1] - vec[i];
        else if(i==sz-1)
            mn = vec[sz-1]-vec[i-1];
        else
            mn = min(vec[i+1]-vec[i], vec[i]-vec[i-1]);

        mx = max(vec[sz-1]-vec[i], vec[i]-vec[0]);

        cout << mn << " " << mx << "\n";
    }

    return 0;
}
