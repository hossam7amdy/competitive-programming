#include <bits/stdc++.h>
using namespace std;

/*
# Statement
    Given a string s, find the length of the longest substring without repeating characters.
    EX. "dvefgdxyz" => 8

# Approach 1: Hash + deque (sliding window)
    - maintain a hash for fast lookup and a deque as sliding window
    - if you encountered a repeated character remove all of its previous including itself
    - with that we sure the deque always contains a unique substring

# Complexity
    - Time complexity: O(n)
    - Space complexity: O(n)
*/

int lengthOfLongestSubstring(string s) {
    deque<char> subString;
    unordered_set<char> visited;

    int maxLen = 0;
    for(auto &ch : s){
        if(visited.count(ch)){
            maxLen = max(maxLen, (int)subString.size());

            while(subString.front() != ch){
                visited.erase(subString.front());
                subString.pop_front();
            }
            visited.erase(ch);
            subString.pop_front();
        }

        visited.insert(ch);
        subString.push_back(ch);
    }

    return max(maxLen, (int)subString.size());
}

int main(){
    cout << lengthOfLongestSubstring("abcabcbb") << "\n";
    cout << lengthOfLongestSubstring("bbbbb") << "\n";
    cout << lengthOfLongestSubstring("pwwkew") << "\n";
    cout << lengthOfLongestSubstring(" ") << "\n";
    cout << lengthOfLongestSubstring("dvdf") << "\n";
    cout << lengthOfLongestSubstring("tmmzuxt") << "\n";
    cout << lengthOfLongestSubstring("dvefgdxyz") << "\n";

    return 0;
}
