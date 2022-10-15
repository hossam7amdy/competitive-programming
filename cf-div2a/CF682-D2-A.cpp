#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    long long a[5]{0}, b[5]{0};
    for(int i=1; i<=n; i++)
        a[i%5]++;
    for(int i=1; i<=m; i++)
        b[i%5]++;

    cout << a[0]*b[0] + a[1]*b[4] + a[2]*b[3] + a[3]*b[2] + a[4]*b[1] << endl;
    return 0;
}
