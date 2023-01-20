// https://leetcode.com/problems/binary-tree-right-side-view/
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

// recursive
class Solution {
    int mxLevel = -1;
    vector<int> result;

    void nowISee(TreeNode* root, int curLevel){
        if(!root)
            return;

        if(curLevel > mxLevel){
            mxLevel = curLevel;
            result.push_back(root->val);
        }

        nowISee(root->right, curLevel + 1);
        nowISee(root->left, curLevel + 1);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
        nowISee(root, 0);
        return result;
    }
};


// iterative
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> ready;

        if(!root)
            return result;

        ready.push(root);
        while(!ready.empty()){
            bool flag = false;
            for(int sz = ready.size(); sz; --sz){
                auto front = ready.front(); ready.pop();
                if(!flag){
                    flag = true;
                    result.push_back(front->val);
                }

                if(front->right)
                    ready.push(front->right);
                if(front->left)
                    ready.push(front->left);
            }
        }

        return result;
    }
};

int main(){

    return 0;
}
