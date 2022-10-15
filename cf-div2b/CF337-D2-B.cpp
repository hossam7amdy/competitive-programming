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

    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int x1 = a*d - c*b;
    int x2 = c*b - a*d;

    if(x1 > 0)
        cout << x1/__gcd(x1,a*d) << "/" << a*d/__gcd(x1,a*d) << "\n";
    else
        cout << x2/__gcd(x2,c*b) << "/" << c*b/__gcd(x2,c*b) << "\n";

    return 0;
}
