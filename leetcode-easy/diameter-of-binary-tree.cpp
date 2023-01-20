// https://leetcode.com/problems/diameter-of-binary-tree
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: for each node find its height

#Complexity
    - Time: O(n^2)
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
    int res = 0;

    int treeHeight(TreeNode *node){
        if(!node)
            return 0;

        int l = 1 + treeHeight(node->left);
        int r = 1 + treeHeight(node->right);

        return l + r;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;

        int l = treeHeight(root->left);
        int r = treeHeight(root->right);
        return max(l,r);
    }
};

int main(){

    return 0;
}
