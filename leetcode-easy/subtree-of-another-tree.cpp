// https://leetcode.com/problems/subtree-of-another-tree/
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool sameTree(TreeNode* root1, TreeNode* root2){
        if(!root1 || !root2)
            return root1 == root2;

        if(root1->val != root2->val)
            return false;

        bool sameLeft = sameTree(root1->left, root2->left);
        bool sameRight = sameTree(root1->right, root2->right);
        return sameLeft && sameRight;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;

        bool isSame = 0;
        if(root->val == subRoot->val)
            isSame = sameTree(root, subRoot);

        bool l = isSubtree(root->left, subRoot);
        bool r = isSubtree(root->right, subRoot);
        return isSame || l || r;
    }
};

int main(){

    return 0;
}
