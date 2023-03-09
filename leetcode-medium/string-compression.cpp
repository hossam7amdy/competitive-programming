// https://leetcode.com/problems/string-compression/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Memory: O(1)
*/

int compress(vector<char>& chars) {
    int idx = 0;

    int count = 1;
    char ch = chars[0];
    for(int i = 1; i < chars.size(); ++i){
        if(ch == chars[i])
            count += 1;
        else{
            chars[idx++] = ch;
            ch = chars[i];

            if(count > 1){
                string num = to_string(count);
                for(auto &digit : num)
                    chars[idx++] = digit;
            }
            count = 1;
        }
    }
    chars[idx++] = ch;
    if(count > 1){
        string num = to_string(count);
        for(auto &digit : num)
            chars[idx++] = digit;
    }
    return idx;
}

int main() {
    return 0;
}
