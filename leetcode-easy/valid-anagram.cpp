#include <bits/stdc++.h>
using namespace std;

/*
    Given two strings `s` and `t`, return true if `t` is an anagram of `s`, and false otherwise.

    SOLUTIONS:
        - sort + one to one comparison -> O(nlogn)
        - freq array -> O(n)


    Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
        - hash map instead of freq array (e.g., unordered_map<char, int> freq) -> O(n)
*/

bool isAnagram(string s, string t) { // O(nlogn)
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    int cursor = 0;
    int sLen = (int)s.size();
    int tLen = (int)t.size();
    while(cursor < sLen && cursor < tLen){
        if(s[cursor] != t[cursor])
            return false;
        ++cursor;
    }

    return cursor == sLen && cursor == tLen;
}

bool isAnagram_(string s, string t) {
    int freq[26] = {0};

    for(auto ch : s)
        ++freq[(int)ch - 'a'];

    for(auto ch : t)
        --freq[(int)ch - 'a'];

    for(auto fq : freq)
        if(fq != 0)
            return false;

    return true;
}


int main(){

    cout << isAnagram_("axzz", "zxa") << "\n";

    return 0;
}
