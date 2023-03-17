// https://leetcode.com/problems/symmetric-tree/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach #1: Recursion

# Complexity:
    - Time O(n)
    - Space O(n)


# Approach #2: Tree serialization

# Complexity:
    - Time O(n)
    - Space O(n)
*/

class Solution {
    bool isSame(TreeNode* t1, TreeNode* t2){
        if(!t1 || !t2)
            return !t1 && !t2;

        if(t1->val != t2->val)
            return false;

        bool left = isSame(t1->left, t2->right);
        bool right = isSame(t1->right, t2->left);
        return left && right;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root->left, root->right);
    }
};

class Solution {
    string serializeLeftTree(TreeNode* root){
        if(!root)
            return "()";

        string str = "(" + to_string(root->val);
        str += serializeLeftTree(root->left);
        str += serializeLeftTree(root->right);
        return str + ")";
    }

    string serializeRightTree(TreeNode* root){
        if(!root)
            return "()";

        string str = "(" + to_string(root->val);
        str += serializeRightTree(root->right);
        str += serializeRightTree(root->left);
        return str + ")";
    }
public:
    bool isSymmetric(TreeNode* root) {
        string left = serializeLeftTree(root->left);
        string right = serializeRightTree(root->right);

        return left == right;
    }
};

int main(){

    return 0;
}
