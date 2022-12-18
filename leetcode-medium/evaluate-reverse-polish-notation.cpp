#include <bits/stdc++.h>
using namespace std;

/*
# Approach: stack
    - keep pushing to stack once an operand calculate

# Complexity
    - Time: O(n)
    - Space: O(n)
*/

int calc(int l, char op, int r){
    if(op == '+')
        return l + r;
    else if(op == '-')
        return l - r;
    else if(op == '*')
        return l * r;
    return l / r;
}

int evalRPN(const vector<string>& tokens) {
    stack<int> nums;
    set<string> ops = set<string>({"+","-","*","/"});

    for(auto token : tokens){
        if(ops.count(token)){
            int r = nums.top();
            nums.pop();

            int l = nums.top();
            nums.pop();

            int res = calc(l,token[0],r);
            nums.push(res);
        } else{
            nums.push(stoi(token));
        }
    }

    return nums.top();
}

int main(){
    cout << evalRPN({"2","1","+","3","*"}) << "\n";
    cout << evalRPN({"4","13","5","/","+"}) << "\n";
    cout << evalRPN({"10","6","9","3","+","-11","*","/","*","17","+","5","+"}) << "\n";

    return 0;
}
