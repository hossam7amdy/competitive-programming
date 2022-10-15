#include<bits/stdc++.h>
using namespace std;

/// https://codeforces.com/contest/79/problem/B

int main()
{
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    vector<long long int> v;
    for(int i=0; i<k; ++i){
        int a,b;
        cin >> a >> b;
        --a,--b;
        v.push_back(b + a * m);
    }

    sort(v.begin(), v.end());

    vector<string> plants {"Carrots","Kiwis","Grapes"};

    while(t--){
        int c = 0;
        int i,j;
        cin >> i >> j;
        --i,--j;
        int res = j + i * m;

        cerr<<"Time : "<<(float)clock()/CLOCKS_PER_SEC<<" s"<<endl;

        if(!k){
            cout << plants[res%3] << "\n";
            continue;
        }

        if(res>v.back()){
            res -= (int)v.size();
            cout << plants[res%3] << "\n";
            continue;
        }

        for(int i=0; i<(int)v.size(); ++i){
            if(v[i]==res){
                cout << "Waste\n";
                break;
            }
            else if(v[i]<res)
                c++;
            else{
                res -= c;
                cout << plants[res%3] << "\n";
                break;
            }
        }
    }
    return 0;
}
