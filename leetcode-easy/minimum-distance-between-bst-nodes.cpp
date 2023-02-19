// https://leetcode.com/problems/minimum-distance-between-bst-nodes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> preorder;
    void getPreorder(TreeNode *root){
        if(!root)
            return;

        getPreorder(root->left);
        preorder.push_back(root->val);
        getPreorder(root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        getPreorder(root);

        int res = 100000;
        for(int i = 1; i < preorder.size(); ++i)
            res = min(res, abs(preorder[i-1] - preorder[i]));

        return res;
    }
};

int main(){

    return 0;
}
