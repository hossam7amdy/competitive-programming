// https://leetcode.com/problems/copy-list-with-random-pointer

#include<bits/stdc++.h>
using namespace std;

/*
# Approach: map
    - store visited nodes to prevent re-creation

# Complexity
    - Time: O(nlogn)
    - Space: O(n)
*/

class Solution {
private:
    map<Node*,Node*> visited;

    Node* getNode(Node* target){
        if(!target)
            return nullptr;

        if(visited.count(target))
            return visited[target];

        return visited[target] = new Node(target->val);
    }

public:
    Node* copyRandomList(Node* head) {
        Node* newHead = new Node(-1); // dummy
        Node* cursor = newHead;

        for(Node* cur = head; cur; cur = cur->next){
            cursor->next = getNode(cur);

            cursor = cursor->next;

            cursor->random = getNode(cur->random);
        }

        return newHead->next;
    }
};

int main(){

    return 0;
}

