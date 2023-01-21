// https://leetcode.com/problems/kth-smallest-element-in-a-bst/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(n)
*/

// iterative
int kthSmallest(TreeNode* root, int k) {
    stack<pair<TreeNode*,bool>> stk;
    stk.push({root,false});

    int res = 0;
    while(!stk.empty()){
        auto top = stk.top(); stk.pop();
        TreeNode* cur = top.first;
        bool ok_left = top.second;

        k -= ok_left;
        if(!k)
            return res = cur->val;

        if(!ok_left){
            stk.push({cur, true});
            if(cur->left)
                stk.push({cur->left, false});
        }else if(cur->right)
            stk.push({cur->right, false});
    }

    return res;
}

// recursive
int count = 0, res = 0;
int kthSmallest(TreeNode* root, int k) {
    if(!root)
        return 0;

    kthSmallest(root->left,k);
    if(++count == k)
        return res = root->val;
    kthSmallest(root->right,k);
    return res;
}


int main(){

    return 0;
}
