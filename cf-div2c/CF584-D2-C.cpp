#include <bits/stdc++.h>
using namespace std;


void fast_IO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    fast_IO();

    int n,t;
    cin >> n >> t;
    t = n - t; // reverse: find t match characters

    char str1[n], str2[n];
    for(int i = 0; i < n; ++i)
        cin >> str1[i];

    int in_both = 0;
    for(int i = 0; i < n; ++i){
        cin >> str2[i];

        if(str1[i] == str2[i])
            ++in_both;
    }

    int max_match = in_both + (n - in_both) / 2;

    if(t > max_match){ // no solution
        cout << "-1\n";
        return 0;
    }

    // Outputting result
    int from1 = t - in_both;
    int from2 = from1;
    for(int i = 0; i < n; ++i){
        if(t && str1[i] == str2[i]){
            cout << str1[i];
            --t;
        }else if(from1 > 0){
            cout << str1[i];
            --from1;
        }
        else if(from2 > 0){
            cout << str2[i];
            --from2;
        }else{
            for(int j = 0; j < 26; ++j){
                char ch = j + 'a';
                if(ch != str1[i] && ch != str2[i]){
                    cout << ch;
                    break;
                }
            }
        }
    }

    return 0;
}
