#include<bits/stdc++.h>
using namespace std;

/*
# Approach 1: Two Pointer
    - store ListNodes into a vector and alternate

# Complexity
    - Time: O(n)
    - Space: O(1)
*/

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int sz = 0;
    for(ListNode* cur = head; cur; cur = cur->next) 
        ++sz;

    if(sz == n) 
        return head->next;

    int toDelIdx = sz - n;
    ListNode* prev = head;
    while(--toDelIdx)
        prev = prev->next;

    prev->next = prev->next->next;
    return head;
}

int main(){

    return 0;
}
