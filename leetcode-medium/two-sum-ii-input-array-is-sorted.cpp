#include <bits/stdc++.h>
using namespace std;

/*
    Given a sorted array, find two numbers such that they add up to a specific target.
    EX. [2,7,11,15], target = 9 => [1,2]

    Approach 1: Binary Search
        - for each number find its complement
    Complexity
        - Time: O(nlogn)
        - Space: O(1)

    Approach 2: Two Pointers
        - place st pointer at begin & one at end
        - keep narrowing the them until target is found
    Complexity
        - Time: O(n)
        - Space: O(1)
*/

vector<int> twoSum(vector<int>& numbers, int target) {
    for(int st = 0; st < (int)numbers.size(); ++st){
        int complement = target - numbers[st];

        auto it = lower_bound(numbers.begin() + st + 1, numbers.end(), complement);
        if(it == numbers.end())
            continue;

        int en = it - numbers.begin();
        if(numbers[st] + numbers[en] == target)
            return {st + 1, en + 1};
    }

    return {-1,-1};
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int st = 0, en = (int)numbers.size() - 1;

    while(st < en){
        int curSum = numbers[st] + numbers[en];

        if(curSum == target)
            break;
        else if(curSum < target)
            ++st;
        else
            --en;
    }

    return {st + 1, en + 1};
}

int main(){

    return 0;
}

