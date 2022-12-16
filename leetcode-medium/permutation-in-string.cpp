#include<bits/stdc++.h>
using namespace std;

/*
# Intuition:
    - valid anagram idea with handling left and right pointers

# Complexity:
    - Time O(n)
    - Space O(2n) -> O(n) => Two frequency arrays
*/

bool checkInclusion(string s1, string s2) {
    if(s1.size() > s2.size())
        return false;

    vector<int> freq1(26, 0), freq2(26, 0);

    int r = 0;
    while(r < s1.size()){
        ++freq1[s1[r] - 'a'];
        ++freq2[s2[r] - 'a'];
        ++r;
    }

    int l = 0;
    while(r < s2.size()){
        if(freq1 == freq2)
            return true;

        --freq2[s2[l] - 'a'];
        ++freq2[s2[r] - 'a'];

        ++l;
        ++r;
    }

    return false;
}

int main() {
    cout << checkInclusion("ab","eidbaooo") << "\n";
    cout << checkInclusion("ab","eidboaoo") << "\n";

    return 0;
}
