#include <bits/stdc++.h>
using namespace std;

/*
Merge the two lists in a one sorted list. Return the head of the merged linked list.

Solution: simulating the merge function form merge-sort algorithm
    - Time: O(n+m)
    - Space: O(1)
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(!list1 && !list2) return nullptr;

    ListNode *head = new ListNode(-1); // dummy
    ListNode *cursor = head;
    while(list1 && list2){
        if(list1->val <= list2->val){
            cursor->next = list1;
            list1 = list1->next;
        }else{
            cursor->next = list2;
            list2 = list2->next;
        }
        cursor = cursor->next;
    }

    if(!list1)
        cursor->next = list2;
    if(!list2)
        cursor->next = list1;

    return head->next; // ignore dummy node
}

int main(){

    return 0;
}
