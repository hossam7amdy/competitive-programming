// https://leetcode.com/problems/happy-number
#include<bits/stdc++.h>
using namespace std;

// recursive
class Solution {
private:
    unordered_map<int,bool> vis;
public:
    bool isHappy(int n) {
        if(n == 1)
            return true;
        if(vis[n])
            return false;

        vis[n] = 1;
        int sum = 0;
        while(n){
            sum += pow(n % 10,2);
            n /= 10;
        }

        return isHappy(sum);
    }
};

// iterative
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> vis;

        while(n != 1){
            if(vis.count(n))
                return false;
            vis.insert(n);

            int next = 0;
            while(n){
                next += pow(n%10, 2);
                n /= 10;
            }
            n = next;
        }
        return true;
    }
};

int main() {

    return 0;
}
