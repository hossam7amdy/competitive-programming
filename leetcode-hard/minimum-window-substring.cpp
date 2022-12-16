#include<bits/stdc++.h>
using namespace std;

int charToIndex(char ch){
    return ch - 'A';
}

bool compareFreq(const vector<int> &v1, const vector<int> &v2){
    for(int i = 0; i < v1.size(); ++i)
        if(v1[i] < v2[i])
            return false;
    return true;
}

string minWindow(string s, string t) {
    if(t.size() > s.size())
        return "";

    vector<int> original(60, 0), compare(60, 0);
    for(auto ch : t)
        ++original[charToIndex(ch)];

    string res = "";

    int l = 0;
    for(int r = 0; r < s.size(); ++r){
        if(!original[charToIndex(s[r])])
            continue;

        ++compare[charToIndex(s[r])];

        while(compareFreq(compare, original)){
            if(!original[charToIndex(s[l])]){
                ++l;
                continue;
            }
            if(compare[charToIndex(s[l])] == original[charToIndex(s[l])])
                break;

            --compare[charToIndex(s[l])];
            ++l;
        }
        if(compareFreq(compare, original) && res == "" || res.size() > r - l + 1)
            res = s.substr(l, r - l + 1);
    }

    return res;
}

int main(){
     cout << minWindow("ADOBECODEBANC","ABC") << "\n";
     cout << minWindow("aaaaaaaaaaaabbbbbcdd","abcdd") << "\n";
    cout << minWindow("acbba","aab") << "\n";

    return 0;
}
