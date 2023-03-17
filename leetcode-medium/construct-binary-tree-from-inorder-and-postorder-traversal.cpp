// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach: Divide and Conquer

# Complexity:
    - Time O(nlogn)
    - Space O(nlogn)
*/

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int st, int en){
        int mid = findIndex(inorder, postorder, st, en);
        if(mid == -1)
            return nullptr;

        postorder.pop_back();
        TreeNode* root = new TreeNode(inorder[mid]);

        root->right = build(inorder, postorder, mid + 1, en);
        root->left  = build(inorder, postorder, st, mid - 1);

        return root;
    }

    int findIndex(vector<int>& inorder, vector<int>& postorder, int st, int en){
        if(postorder.size() == 0)
            return -1;

        while(st <= en){
            if(inorder[st] == postorder.back())
                return st;
            ++st;
        }

        return -1;
    }

int main(){

    return 0;
}
