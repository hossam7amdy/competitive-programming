#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Space: O(1)
*/
ListNode* reverseList(ListNode* head) {
    if(!head) return nullptr;

    ListNode *cur = head, *tail = head;
    while(cur){
        ListNode *temp = cur->next;

        cur->next = head;
        head = cur;

        cur = temp;
    }
    tail->next = nullptr;

    return head;
}

int main(){

    return 0;
}
