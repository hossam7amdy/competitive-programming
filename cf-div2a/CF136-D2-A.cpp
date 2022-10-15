#include<iostream>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/136/problem/A


int main(){
    int n;
    cin >> n;
    vector<int> v2,v1(n,0);

    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        v2.push_back(val);
        v1[v2[i]-1] = i+1;
    }

    for(auto& val : v1)
        cout << val << " ";

    return 0;
}
