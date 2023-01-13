// https://leetcode.com/problems/binary-tree-preorder-traversal
#include<bits/stdc++.h>
using namespace std;

// recursive
vector<int> preorder;
vector<int> preorderTraversal(TreeNode* root) { // O(n)
    if(!root)
        return preorder;

    preorder.push_back(root->val);
    preorderTraversal(root->left);
    preorderTraversal(root->right);

    return preorder;
}

// iterative
vector<int> preorderTraversal(TreeNode* root) { // O(n)
    stack<TreeNode*> st;
    vector<int> preorder;

    if(!root)
        return preorder;

    st.push(root);
    while(!st.empty()){
        auto top = st.top(); st.pop();
        preorder.push_back(top->val);

        if(top->right)
            st.push(top->right);
        if(top->left)
            st.push(top->left);
    }

    return preorder;
}

int main() {

    return 0;
}
