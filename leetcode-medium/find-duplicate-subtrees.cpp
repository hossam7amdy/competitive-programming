// https://leetcode.com/problems/find-duplicate-subtrees/
#include<bits/stdc++.h>
using namespace std;

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
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;

        serializeTree(root);

        for(auto &[_, roots] : serials)
            if(roots.size() > 1)
                res.push_back(roots.front());

        return res;
    }

private:
    unordered_map<string, vector<TreeNode*>> serials;

    string serializeTree(TreeNode* root){
        if(!root)
            return "()";

        string treeSerial = "(" + to_string(root->val) +
            serializeTree(root->left) + serializeTree(root->right) + ")";

        serials[treeSerial].push_back(root);
        return treeSerial;
    }
};

int main() {
    return 0;
}
