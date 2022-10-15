#include<iostream>
#include<sstream>
#include<set>
using namespace std;

/// https://codeforces.com/contest/339/problem/A


int main(){
    string str;
    multiset<int> mst;

    cin >> str;

    for(int i=0; i<(int)str.size(); i+=2){
        if(str[i]=='1')
            mst.insert(1);
        else if(str[i]=='2')
            mst.insert(2);
        else if(str[i]=='3')
            mst.insert(3);
    }

    for(auto it = mst.begin(); it!=mst.end(); it++){
        if(it!=mst.begin())
            cout << '+';
        cout << *it;
    }

    return 0;
}
