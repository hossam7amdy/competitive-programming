#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
    string s,t;
    cin >> s >> t;

    if((int)s.size()<(int)t.size()){
        cout << "need tree\n";
        return 0;
    }
    string test = s;
    for(int i=0; i<(int)t.size(); i++){
        int idx;
        if((idx = test.find(t[i]))==-1){
            cout << "need tree\n";
            return 0;
        }
        test.erase(idx,1);
    }

    if((int)s.size()==(int)t.size())
        cout << "array\n";
    else{
        for(int i=0,j=0; i<(int)s.size(); i++){
            if(s[i]==t[j])
                j++;
            if(j==(int)t.size()-1){
                cout << "automaton\n";
                return 0;
            }
        }
        cout << "both\n";
    }
}
