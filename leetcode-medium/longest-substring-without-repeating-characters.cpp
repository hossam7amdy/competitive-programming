#include <bits/stdc++.h>
using namespace std;

/*
# Statement
    Given a string s, find the length of the longest substring without repeating characters.
    EX. "dvefgdxyz" => 8

# Approach 1: Hash Map (sliding window)
    - expand window as long as no duplicate

# Complexity
    - Time complexity: O(n)
    - Space complexity: O(n)
*/

int lengthOfLongestSubstring(string s) {
    unordered_map<char,int> visited;

    int l = 0, maxLen = 0;
    for(int r = 0; r < s.size(); ++r){
        ++visited[s[r]];

        while(visited[s[r]] > 1){
            --visited[s[l]];
            ++l;
        }

        maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
}

int main(){
    cout << lengthOfLongestSubstring("abcabcbb") << "\n"; // 3
    cout << lengthOfLongestSubstring("bbbbb") << "\n"; // 1
    cout << lengthOfLongestSubstring("pwwkew") << "\n"; // 3
    cout << lengthOfLongestSubstring(" ") << "\n"; // 1
    cout << lengthOfLongestSubstring("dvdf") << "\n"; // 3
    cout << lengthOfLongestSubstring("tmmzuxt") << "\n"; // 5
    cout << lengthOfLongestSubstring("dvefgdxyz") << "\n"; // 8

    return 0;
}
