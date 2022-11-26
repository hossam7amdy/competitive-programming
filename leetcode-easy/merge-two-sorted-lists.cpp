#include <bits/stdc++.h>
using namespace std;

/*
    Merge the two lists in a one sorted list. Return the head of the merged linked list.

    Solution: simulating the merge function form merge-sort algorithm
        - Time: O(n+m)
        - Space: O(n+m)
*/


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // iterative
    // if one list only
    if(!list2) return list1;
    if(!list1) return list2;

    // compare and merge as logn as there are elements in the two lists
    ListNode *result;
    if(list1->val <= list2->val){
        result = list1;
        list1 = list1->next;
    }else{
        result = list2;
        list2 = list2->next;
    }

    ListNode *cursor = result;
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

    // check the remaining list
    if(list1){
        cursor->next = list1;
    }else{
        cursor->next = list2;
    }

    return result;
}


ListNode* mergeTwoLists_(ListNode* list1, ListNode* list2) { // recursive
    if(!list1 && !list2)
        return nullptr;

    if(!list1) return list2;
    if(!list2) return list1;

    if(list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

int main(){

    return 0;
}
