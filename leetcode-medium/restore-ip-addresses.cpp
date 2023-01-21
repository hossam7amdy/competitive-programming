// https://leetcode.com/problems/restore-ip-addresses/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: [ Backtracking ]

#Complexity
    - Time: O(m^n) => m levels each one has n choices
    - Space: O(mn)
*/

class Solution {
    string str;
    vector<string> Ips;

    vector<string> curIp;
    void backtrack(int idx){
        if(idx == str.size()){
            if(curIp.size() != 4)
                return;

            string res = curIp[0];
            for(int i = 1; i < curIp.size(); ++i)
                res += '.' + curIp[i];

            if(res.size() - 3 != str.size())
                return;

            Ips.push_back(res); // ok
            return;
        }

        if(curIp.size() == 4)
            return;

        string num = "";
        for(int i = idx; i < str.size(); ++i){
            if(0 <= stoi(num + str[i]) && stoi(num + str[i]) <= 255){
                num += str[i];

                if(num.size() > 1 && num[0] == '0') // leading zero
                    break;

                curIp.push_back(num); // do

                backtrack(i+1);      // recurse

                curIp.pop_back();   // undo
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        str = s;
        backtrack(0);
        return Ips;
    }
};

int main(){

    return 0;
}
