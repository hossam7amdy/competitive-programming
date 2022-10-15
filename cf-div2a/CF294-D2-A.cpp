#include<iostream>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/294/problem/A

int main(){
    vector<int> vec;
    int n, x, y;

    cin >> n;
    while(n--){
        cin >> x;
        vec.push_back(x);
    }

    cin >> n;
    while(n--){
        cin >> x >> y;
        x--; // Zero based
        if(x == 0)
            vec[x+1] = vec[x+1] + vec[x] - y;
        else if(x == vec.size()-1)
            vec[x-1] = vec[x-1] + y - 1;
        else{
            vec[x+1] = vec[x+1] + vec[x] - y;
            vec[x-1] = vec[x-1] + y - 1;
        }
        vec[x] = 0;
    }

    for(auto& val : vec)
        cout << val << "\n";

    return 0;
}

