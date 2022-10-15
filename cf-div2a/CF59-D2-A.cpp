#include <iostream>
#include <string>
using namespace std;

///https://codeforces.com/contest/59/problem/A

int main()
{
    string str;
    int u=0, l=0;

    cin >> str;

    for(int i=0; i<str.size(); i++){
        if('A' <= str[i] && str[i] <= 'Z')
            u++;
        else
            l++;
    }

    if(u>l){
        for(int i=0; i<str.size(); i++)
            str[i] = toupper(str[i]);
    }
    else{
        for(int i=0; i<str.size(); i++)
            str[i] = tolower(str[i]);
    }

    cout << str << endl;

    return 0;
}
