#include<iostream>
#include<vector>
using namespace std;

/// https://codeforces.com/contest/47/problem/B

int main(){
    string str;
    string arr[3];
    for(int i=0; i<3; i++)
    {
        cin >> str;
        if(str[1]=='<')
        {
            arr[i] += str[0];
            arr[i] += str[2];
        }

        else
        {
            arr[i] += str[2];
            arr[i] += str[0];
        }

    }

    str = "";

    string s1 = arr[0];
    string s2 = arr[1];
    string s3 = arr[2];

    if(s1==s2 || s1 == s3)
    {
        cout << "Impossible";
        return 0;
    }

    if(s1[0] == s2[0])
    {
        str += s1[0];
        str += s3;
    }
    else if(s1[0] == s3[0])
    {
        str += s1[0];
        str += s2;
    }
    else if(s2[0] == s3[0])
    {
        str += s2[0];
        str += s1;
    }
    else
    {
        cout << "Impossible";
        return 0;
    }

    cout << str;


    return 0;
}
