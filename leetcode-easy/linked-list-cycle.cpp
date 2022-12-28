#include <bits/stdc++.h>
using namespace std;

/*
#Intuition
    - Imagine two runners one is faster than the other, and he is fast enough to finish a cycle and reach him again.

# Complexity
    - Time: O(n)
    - Space: O(1)
*/

bool hasCycle(ListNode *head) { // O(n)
    if(!head) return false;

    ListNode *tortoise, *hare;
    tortoise = hare = head;
    while(hare && hare->next){
        tortoise = tortoise->next;
        hare = hare->next->next;

        if(hare == tortoise)
            return true;
    }

    return false;
}

int main(){

    return 0;
}
