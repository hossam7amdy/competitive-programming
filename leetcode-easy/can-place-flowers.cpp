// https://leetcode.com/problems/can-place-flowers/
#include<bits/stdc++.h>
using namespace std;

/*
#Complexity
    - Time: O(n)
    - Space: O(1)
*/

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int canPlaced = 0;
    int sz = flowerbed.size();

    for(int i = 0; i < sz; ++i){
        if(flowerbed[i] == 0){
            bool leftIsEmpty  = (i == sz - 1 || flowerbed[i + 1] == 0);
            bool rightIsEmpty = (i == 0      || flowerbed[i - 1] == 0);

            if(leftIsEmpty && rightIsEmpty){
                canPlaced++;
                flowerbed[i] = 1;
            }

            if(canPlaced == n)
                return true;
        }
    }
    return canPlaced >= n;
}

int main(){

    return 0;
}

