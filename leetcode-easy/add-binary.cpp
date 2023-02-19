// https://leetcode.com/problems/add-binary/
#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int a_sz = a.size();
    int b_sz = b.size();
    string res = "";
    int carry = 0;
    for(int i = 0; i < max(a_sz, b_sz); ++i){
        int n1 = i < a_sz ? a[i] - '0' : 0;
        int n2 = i < b_sz ? b[i] - '0' : 0;
        carry = carry + n1 + n2;
        res += carry == 2 || carry == 0 ? '0' : '1';
        carry = carry >= 2;
    }
    if(carry) res += '1';
    reverse(res.begin(), res.end());
    return res;
}

int main(){

    return 0;
}
