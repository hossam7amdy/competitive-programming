// https://leetcode.com/problems/add-to-array-form-of-integer/
#include<bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
    reverse(num.begin(), num.end());
    int carry = 0;
    int sz = num.size();
    for(int i = 0; i < sz || k; ++i, k /= 10){
        int n1 = i < sz ? num[i] : 0;
        int n2 = k % 10;
        int sum = carry + n1 + n2;
        if(sum > 9){
            sum -= 10;
            carry = 1;
        }else
            carry = 0;
        if(i < sz)
            num[i] = sum;
        else
            num.push_back(sum);
    }
    if(carry)
        num.push_back(carry);

    reverse(num.begin(), num.end());
    return num;
}

int main(){

    return 0;
}
