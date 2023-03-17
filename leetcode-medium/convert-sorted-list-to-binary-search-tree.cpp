// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach #1: Divide and Conquer

# Complexity:
    - Time O(nlogn)
    - Space O(n)
*/

class Solution {
    ListNode* getMiddle(ListNode* head){
        ListNode *slow, *fast, *prev;
        prev = slow = fast = head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return slow;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;

        ListNode* left   = head;
        ListNode* middle = getMiddle(head);
        ListNode* right  = middle->next;

        middle -> next = nullptr;
        TreeNode* root = new TreeNode(middle->val);
        if(head == middle) return root;

        root->left = sortedListToBST(left);
        root->right = sortedListToBST(right);
        return root;
    }
};

int main(){

    return 0;
}
