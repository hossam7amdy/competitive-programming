// https://leetcode.com/problems/balanced-binary-tree/
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
    bool is_balanced = true;
    int treeHeight(TreeNode* root){
        if(!root || !is_balanced)
            return -1;

        int l = 1 + treeHeight(root->left);
        int r = 1 + treeHeight(root->right);

        if(abs(l-r) > 1)
            is_balanced = false;

        return max(l,r);
    }
public:
    bool isBalanced(TreeNode* root) {
        treeHeight(root);
        return is_balanced;
    }
};

int main(){

    return 0;
}

