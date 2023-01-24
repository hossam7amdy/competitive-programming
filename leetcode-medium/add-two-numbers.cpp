// https://leetcode.com/problems/add-two-numbers
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: normal sum with careful carry handling

#Complexity
    - Time: O(max(n,m))
    - Space: O(max(n,m))
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(-1);

    bool carry = 0;
    ListNode* cursor = head;
    while(l1 || l2){
        int left = l1 ? l1->val : 0;
        int right = l2 ? l2->val : 0;
        int sum = left + right + carry;

        carry = sum > 9;
        if(carry) sum -= 10;

        cursor->next = l1 ? l1 : l2;
        cursor = cursor->next;
        cursor->val = sum;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }

    if(carry)
        cursor->next = new ListNode(1);
    return head->next;
}

int main(){

    return 0;
}
