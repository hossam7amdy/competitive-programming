#include<iostream>
using namespace std;

/// https://codeforces.com/contest/443/problem/A

/*
can be done with several ways:
freq array
set ...
*/

int main(){
    string str;
    int arr[27] {0};
    int cnt = 0;

    getline(cin, str);

    for(int i=0; i<(int)str.size(); i++){
        char ch = str[i];
        if('a' <= ch && ch <= 'z')
            arr[(int)(ch-'a')]++;
    }

    for(auto& val : arr){
        if(val>0)
            cnt++;
    }

    cout << cnt;

    return 0;
}
