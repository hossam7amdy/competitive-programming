// https://leetcode.com/problems/validate-binary-search-tree/
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
    vector<int> sorted;
    void helper(TreeNode* root){
        if(!root)
            return;

        helper(root->left);
        sorted.push_back(root->val);
        helper(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        helper(root);

        for(int i = 1; i < sorted.size(); ++i)
            if(sorted[i-1] >= sorted[i])
                return false;

        return true;
    }
};

int main(){

    return 0;
}
