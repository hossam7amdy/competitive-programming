#include <bits/stdc++.h>
using namespace std;

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main(){
    fast();
    //readFile();

    int n,q, total = 0, pos = 0, cnt = 0;
    cin >> n >> q;
    vector<int> app1(n+1, 0), app2(n+1, 0), que(300001);

    while(q--){
        int type, x;
        cin >> type >> x;

        if(type == 1){
            ++app1[x];
            ++app2[x];
            que[++cnt] = x;
            ++total;
        }
        else if(type == 2){
            total -= app1[x];
            app1[x] = 0;
        }
        else{
            while(pos < x){
                int y = que[++pos];

                if(app2[y])
                    --app2[y];

                if(app1[y] > app2[y]){
                    --total;
                    --app1[y];
                }
            }
        }

        cout << total << "\n";
    }

    return 0;
}
