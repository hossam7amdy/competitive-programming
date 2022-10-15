#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> CELL;
#define x first
#define y second
#define ll long long

void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
void readFile(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int cnt = 0;
void dfs(int q, int d1, int d2){
    if(q == 0){
        if(d1 == d2)
            ++cnt;
        return;
    }

    dfs(q-1, d1, d2+1);
    dfs(q-1, d1, d2-1);
}

int main(){
    fast_IO();

    int d1 = 0, d2 = 0, q = 0;
    string s1, s2;
    cin >> s1 >> s2;

    for(int i = 0; s1[i] != '\0'; ++i)
        (s1[i] == '+') ? d1++ : d1--;

    for(int i = 0; s2[i] != '\0'; ++i){
        if(s2[i] == '+')
            ++d2;
        else if(s2[i] == '-')
            --d2;
        else
            ++q;
    }

    double ans = 0;
    if(!q)
        (d1 == d2) ? ans = 1 : ans = 0;
    else{
        dfs(q, d1, d2);

        ans = cnt / pow(2,q);
    }

    printf("%0.12f", ans);
    return 0;
}
