#include<bits/stdc++.h>
using namespace std;

int freq[130] {0};
bool is_palindrome(){
    int c = 0;
    for(int i=97; i<123; i++){
        c+=(freq[i]%2 != 0);
        if(c>1){
            --freq[i];
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;

    for(int i=0; i<(int)s.size(); ++i)
        freq[(int)s[i]]++;

    string winner[2] {"First", "Second"};
    int flag = 0;
    while(!is_palindrome())
        flag = !flag;

    cout << winner[flag] << endl;
    return 0;
}
