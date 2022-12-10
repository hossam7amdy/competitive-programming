#include <bits/stdc++.h>
using namespace std;

/*
# Statement
    Find two lines that together with the x-axis form a container, such that the container contains the most water.
    EX. [1,8,6,2,5,4,8,3,7] => 49

#Intuition
    If we can choose two max heights then we guarantee we have the max area.

# Approach 1: Two pointers + Greedy
    - declare `bestArea` variable and `st` & `en` pointers
    - Choose best hight and keep move `st` and `en` pointers
    - and greedily maximize `bestArea` with each step

# Complexity
    - Time complexity: O(n)
    - Space complexity: O(1)
*/

int maxArea(vector<int>& height) {
    int st = 0, en = height.size() - 1;
    int bestArea = 0;

    while(st < en){
        int leftHeight = height[st];
        int rightHeight = height[en];

        int curArea = min(leftHeight,rightHeight) * (en - st);
        bestArea = max(bestArea, curArea);

        if(right > left)
            ++st;
        else
            --en;
    }

    return bestArea;
}

int main(){

    return 0;
}
