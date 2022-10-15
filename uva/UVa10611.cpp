#include<bits/stdc++.h>
using namespace std;

void Run(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin);
	freopen("out.txt", "wt", stdout);
#endif
}



int main(){
   // Run();

    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    int q;
    cin >> q;
    while(q--){
        int shorter, he, taller;
        cin >> he;
        shorter = taller = 0;

        for(int i=0; i<n; i++){
            if(v[i]<he)
                shorter = v[i];
            if(v[i]>he && !taller)
                taller = v[i];
        }

        if(!shorter)
                cout << "X ";
        else
            cout << shorter << " ";

        if(!taller)
            cout << "X\n";
        else
            cout << taller << "\n";
    }

    return 0;
}
