// https://leetcode.com/problems/check-completeness-of-a-binary-tree/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach: BFS

# Complexity:
    - Time O(n)
    - Space O(n)
*/

bool isCompleteTree(TreeNode* root) {
    bool notComplete = false;
    queue<TreeNode*> ready;

    ready.push(root);
    while(!ready.empty()){
        auto front = ready.front(); ready.pop();
        if(front == nullptr)
            notComplete = true;
        else{
            if(notComplete)
                return false;

            ready.push(front->left);
            ready.push(front->right);
        }
    }

    return true;
}

int main(){

    return 0;
}
