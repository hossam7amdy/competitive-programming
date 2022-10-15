#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    n = 2 * n + 1;
    vector<int> vec(n);

    for(int i=0; i<n; i++)
        cin >> vec[i];


    while(k){

        for(int i=n-2;(i>0 && k); i-=2){
            if(vec[i-1]<vec[i]-1 && vec[i]-1>vec[i+1]){
                vec[i]--;
                k--;
            }
        }
    }

    for(auto& val : vec)
        cout << val << " ";


    return 0;
}
