// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int pathLen = 0;
    void maxZigZag(TreeNode* node, int left, int right){
        if(!node)
            return;

        if(node->left)
            maxZigZag(node->left, 0, left + 1);
        if(node->right)
            maxZigZag(node->right, right + 1, 0);

        pathLen = max(pathLen, max(left, right));
    }

public:
    int longestZigZag(TreeNode* root) {
        maxZigZag(root, 0, 0);
        return pathLen;
    }
};

int main(){

    return 0;
}
