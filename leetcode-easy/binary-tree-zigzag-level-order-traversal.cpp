// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include<bits/stdc++.h>
using namespace std;

/*

# Complexity
    - Time: O(n)
    - Memory: O(n)
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;

    bool flag = false;
    queue<TreeNode*> ready;
    ready.push(root);

    while(!ready.empty()){
        vector<int> curLevel;
        for(int sz = ready.size(); sz; --sz){
            auto front = ready.front();
            ready.pop();
            curLevel.push_back(front->val);
            if(front->left)
                ready.push(front->left);
            if(front->right)
                ready.push(front->right);
        }
        if(flag)
            reverse(curLevel.begin(), curLevel.end());

        flag = !flag;
        res.push_back(curLevel);
    }

    return res;
}

int main(){

    return 0;
}
