// https://leetcode.com/problems/sum-root-to-leaf-numbers/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach #1: Recursion

# Complexity:
    - Time O(n)
    - Space O(n)
*/

int res = 0;
int sumNumbers(TreeNode* root, int num = 0) {
    if(!root)
        return num;

    num = num * 10 + root->val;
    sumNumbers(root->left, num);
    sumNumbers(root->right, num);

    if(!root->left && !root->right)
        res += num;
    return res;
}

int main(){

    return 0;
}
