#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/699/problem/A

int main(){
    int const MAX = 2000000000;
    int N;
    cin >> N;
    vector<char> v(N);

    for(int i=0; i<N; i++)
        cin >> v[i];


    int pos = MAX;
    int Ri = MAX, Li = 0;
    for(int i=0; i<N; i++){
        int val;
        cin >> val;

        if(v[i]=='R')
            Ri = val;
        else
            Li = val;

        if(Ri<Li)
            pos = min(pos, (Li-Ri));
    }

    if(pos!=MAX)
        cout << pos/2;
    else
        cout << -1;

    return 0;
}
