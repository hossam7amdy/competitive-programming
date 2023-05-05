// https://leetcode.com/problems/smallest-number-in-infinite-set/
#include<bits/stdc++.h>
using namespace std;

class SmallestInfiniteSet {
    int cur{};
    set<int> heap;
public:
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        int res = cur;
        if(heap.empty()){
            ++cur;
            return res;
        }

        auto it = heap.begin();
        if(*it <= res){
            if(*it == res)
                ++cur;

            res = *it;
            heap.erase(it);
            return res;
        }

        ++cur;
        return res;
    }

    void addBack(int num) {
        heap.insert(num);
    }
};

int main(){

    return 0;
}
