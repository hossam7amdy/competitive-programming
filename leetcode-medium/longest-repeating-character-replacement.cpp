#include <bits/stdc++.h>
using namespace std;


int characterReplacement(string s, int k) { // O(n)
    vector<int> freq(26,0);
    int maxLen = 0;

    int l = 0;
    int topFreq = 0;
    for(int r = 0; r < (int)s.size(); ++r){
        topFreq = max(topFreq, ++freq[s[r] - 'A']);

        while((r - l + 1) - topFreq > k){
            --freq[s[l] - 'A'];
            ++l;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main(){
    cout << characterReplacement("ABAB", 2) << "\n";
    cout << characterReplacement("AABABBA", 1) << "\n";

    return 0;
}
