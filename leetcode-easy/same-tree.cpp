// https://leetcode.com/problems/same-tree
#include<bits/stdc++.h>
using namespace std;

// recursive
bool isSameTree(TreeNode* p, TreeNode* q) { // O(n)
    if(!p && !q)
        return true;

    if(!p && q || p && !q)
        return false;
    if(p->val != q->val)
        return false;

    bool l = isSameTree(p->left, q->left);
    bool r = isSameTree(p->right, q->right);
    return l && r;
}

// iterative
bool isSameTree(TreeNode* p, TreeNode* q) { // O(n)
    if(!p && !q) return true;

    if(!p)
        return isSameTree(q,p);
    if(p && !q)
        return false;

    stack<TreeNode*> pTree, qTree;
    pTree.push(p);
    qTree.push(q);

    while(!pTree.empty() && !qTree.empty()){
        auto pTop = pTree.top(); pTree.pop();
        auto qTop = qTree.top(); qTree.pop();

        if(pTop->val != qTop->val)
            return false;

        if(pTop->left)
            pTree.push(pTop->left);
        if(qTop->left)
            qTree.push(qTop->left);

        if(pTree.size() != qTree.size())
            return false;

        if(pTop->right)
            pTree.push(pTop->right);
        if(qTop->right)
            qTree.push(qTop->right);
    }

    return pTree.empty() && qTree.empty();
}

int main() {

    return 0;
}
