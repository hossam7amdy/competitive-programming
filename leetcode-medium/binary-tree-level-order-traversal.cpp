// https://leetcode.com/problems/binary-tree-level-order-traversal/
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        queue<TreeNode*> ready;

        if(!root)
            return levels;

        ready.push(root);
        while(!ready.empty()){
            vector<int> curLevel;

            for(int sz = ready.size(); sz; --sz){
                auto front = ready.front(); ready.pop();
                curLevel.push_back(front->val);

                if(front->left)
                    ready.push(front->left);
                if(front->right)
                    ready.push(front->right);
            }

            levels.push_back(curLevel);
        }

        return levels;
    }
};

int main(){

    return 0;
}
