// https://leetcode.com/problems/merge-k-sorted-lists

#include<bits/stdc++.h>
using namespace std;

/*
#Approach: merge 2 by 2 to get final result

#Complexity
    - Time: O(N*k) k lists * N length
    - Space: O(1)
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;

        while(l1 && l2){
            if(l1->val < l2->val)
                cur->next = l1, l1 = l1->next;
            else
                cur->next = l2, l2 = l2->next;
            cur = cur->next;
        }

        if(l1)
            cur->next = l1;
        if(l2)
            cur->next = l2;

        return head->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;

        ListNode *result = lists[0];
        for(int i = 1; i < lists.size(); ++i)
            result = merge(result, lists[i]);

        return result;
    }
};

int main(){

    return 0;
}
