// https://leetcode.com/problems/validate-stack-sequences/
#include<bits/stdc++.h>
using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int idx = 0;
    for(auto& num : pushed){
        st.push(num);
        while(!st.empty() && st.top() == popped[idx]){
            ++idx;
            st.pop();
        }
    }

    return idx == pushed.size();
}

int main(){

    return 0;
}
