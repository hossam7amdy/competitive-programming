// https://leetcode.com/problems/linked-list-random-node/
#include<bits/stdc++.h>
using namespace std;

/*
# Complexity
    - Time: O(n)
    - Space: O(1)
*/

class Solution {
    int size{};
    ListNode* head{};
public:
    Solution(ListNode* head): head(head) {
        while(head){
            ++size;
            head = head->next;
        }
    }

    int getRandom() {
        int randIdx = rand() % size;
        auto cur = head;
        while(randIdx){
            --randIdx;
            cur = cur->next;
        }
        return cur->val;
    }
};

int main(){

    return 0;
}
