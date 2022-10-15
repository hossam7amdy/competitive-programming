#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;


int main(){
    int pos[10001];
    int n,l;
    cin >> n >> l;
    for(int i=0; i<n; ++i) cin >> pos[i];

    sort(pos, pos+n);

    double distance{};
    if(pos[0] != 0)
        distance = pos[0];
    if(pos[n-1]!=l)
        distance = max(distance, (double)l-pos[n-1]);

    for(int i=1; i<n; ++i){
        double new_dis = (double)(pos[i]-pos[i-1])/2;
        distance = max(new_dis, distance);
    }

    cout << fixed << showpoint;
    cout << setprecision(9) << distance << endl;

    return 0;
}
