#include<bits/stdc++.h>
using namespace std;

/*
# Approach 1: Two Pointer
    - store ListNodes into a vector and alternate

# Complexity
    - Time: O(n)
    - Space: O(n)

# Approach 2:
    - find middle -> split -> merge
    - [1,2,3,4,5] will be:
        1- [1,2,3]
        2- [4,5] reverse -> [5,4]
    - merge => [1,5,2,4,3]

# Complexity
    - Time: O(n)
    - Space: O(1)
*/

/*================ Approach 1 ===================*/
void reorderList(ListNode* head) {
    vector<ListNode*> nodes;
    for(ListNode *cur = head; cur; cur = cur->next)
        nodes.push_back(cur);

    int st = 0, en = nodes.size() - 1;
    while(st < en){
        nodes[st]->next = nodes[en];
        ++st;
        if(nodes[st] != nodes[en]){
            nodes[en]->next = nodes[st];
            --en;
        }
    }
    nodes[en]->next = nullptr;
}

/*================ Approach 2 ===================*/
class Solution {
    ListNode* reverseList(ListNode* head){
        ListNode *cursor = head, *tail = head;
        while(cursor){
            ListNode* temp = cursor->next;

            cursor->next = head;
            head = cursor;

            cursor = temp;
        }
        tail->next = nullptr;
        return head;
    }

    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head, *fast = head;

        ListNode* prev = slow;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        return reverseList(slow);
    }
public:
    void reorderList(ListNode* head) {
        if(!head->next) return;

        ListNode *mid = getMiddle(head);

        while(head && mid){
            ListNode *st = head, *en = mid;

            head = head->next;
            mid = mid->next;

            st->next = en;
            if(head)
                en->next = head;
        }
    }
};

int main(){

    return 0;
}
