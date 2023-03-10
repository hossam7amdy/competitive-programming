// https://leetcode.com/problems/minimum-time-to-complete-trips/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Space: O(n)
*/

ListNode *detectCycle(ListNode *head) {
    if(!head)
        return nullptr;

    unordered_set<ListNode*> vis;
    while(head){
        if(vis.count(head))
            return head;

        vis.insert(head);
        head = head->next;
    }

    return nullptr;
}

int main(){

    return 0;
}
