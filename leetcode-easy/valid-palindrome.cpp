#include <bits/stdc++.h>
using namespace std;

/*
    Given a string s, return true if it is a palindrome, or false otherwise.
    EX. "A man, a plan, a canal: Panama" => "amanaplanacanalpanama" => true

    Approach 1: two pointers
        - pointer st at begin & pointer en at end
        - at any point of time if s[st] != s[en] then not palindrome otherwise it is a palindrome
    COMPLEXITY
        - Time: O(n)
        - Space: O(1)
*/

bool isPalindrome(string s) {
    int st = 0, en = (int)s.size() - 1;

    while(st < en){
        if(!isalnum(s[st])){
            ++st;
            continue;
        }
        if(!isalnum(s[en])){
            --en;
            continue;
        }
        if(tolower(s[st++]) != tolower(s[en--]))
            return false;
    }

    return true;
}

int main(){
    cout << isPalindrome("A man, a plan, a canal: Panama") << "\n";
    cout << isPalindrome("race a car") << "\n";
    cout << isPalindrome(" ") << "\n";

    return 0;
}
