// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(n)
*/

class Solution {
    int preorderIdx = 0;
    vector<int> preorder;
    unordered_map<int,int> inorderValueToIndex;

    TreeNode* TreeBuilder(int left, int right){
        if(left > right)
            return nullptr;

        int val = preorder[preorderIdx++];
        int mid = inorderValueToIndex[val];

        TreeNode* root = new TreeNode(val);
        root->left = TreeBuilder(left, mid-1);
        root->right = TreeBuilder(mid+1,right);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder_, vector<int>& inorder) {
        preorder = preorder_;
        for(int i = 0; i < inorder.size(); ++i)
            inorderValueToIndex.insert({inorder[i],i});

        return TreeBuilder(0, preorder.size()-1);
    }
};

int main(){

    return 0;
}
