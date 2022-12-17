#include<bits/stdc++.h>
using namespace std;

/*
# Approach 1: stack + minHeap
    - normal stack with minHeap to getMin in O(1)

# Complexity
    - Time: O(logn)
    - Space: O(n)

# Approach 2: stack + monotonic stack
    - replace minHeap with monotonic stack
    -

# Complexity
    - Time: O(1)
    - Space: O(n)
*/

class MinStack_ {
private:
    vector<int> st;
    unordered_map<int,int> exist;
    priority_queue <int, vector<int>, greater<int> > minHeap;

public:
    MinStack() {}

    void push(int val) {
        st.push_back(val);
        minHeap.push(val);
        exist[val]++;
    }

    void pop() {
        int top = st.back();

        exist[top]--;
        if(top == minHeap.top())
            minHeap.pop();

        st.pop_back();
    }

    int top() {
        return st.back();
    }

    int getMin() {
        while(!exist[minHeap.top()])
            minHeap.pop();
        return minHeap.top();
    }
};

class MinStack {
private:
    stack<int> stk;
    stack<int> monoStk;

public:
    MinStack() {}

    void push(int val) {
        stk.push(val);

        if(monoStk.empty() || val <= monoStk.top())
            monoStk.push(val);
    }

    void pop() {
        if(stk.top() == monoStk.top())
            monoStk.pop();

        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return monoStk.top();
    }
};


int main(){

    return 0;
}
