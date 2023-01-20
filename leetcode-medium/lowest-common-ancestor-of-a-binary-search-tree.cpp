// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(n)
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;

        if(p->val < root->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);

        return root;
    }
};

int main(){

    return 0;
}
