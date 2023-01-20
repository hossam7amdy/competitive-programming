// https://leetcode.com/problems/count-good-nodes-in-binary-tree/
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
    static const int OO = 1e4 + 1;
public:
    int goodNodes(TreeNode* root, int mx = OO) {
        if(mx == OO) // first call
            return goodNodes(root, root->val);
        if(!root) // base
            return 0;

        int good = root->val >= mx;

        mx = max(mx, root->val); // update max

        good += goodNodes(root->left, mx);
        good += goodNodes(root->right, mx);

        return good;
    }
};

int main(){

    return 0;
}
