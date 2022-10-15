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


int main(){
    fast_IO();

    /*
    1) maximize { p1, r1 }
    2) minimize { p2 }
    3) apply the formula
    */

    // time O(n)
    int n,m,k;

    cin >> n;
    double r1 = 0;
    while(n--){
        double x;
        cin >> x;
        r1 = max(r1, x);
    }

    cin >> m;
    double p1 = 0;
    while(m--){
        double y;
        cin >> y;
        p1 = max(p1, y);
    }

    cin >> k;
    double p2 = 5001;
    while(k--){
        double z;
        cin >> z;
        p2 = min(p2, z);
    }

    double A,B;
    cin >> A >> B;

    printf("%0.12f\n", sqrt((B* p1 * pow(r1,2)) / (A*p2 + B*p1)));

    return 0;
}
