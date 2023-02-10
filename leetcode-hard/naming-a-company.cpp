// https://leetcode.com/problems/naming-a-company/
#include<bits/stdc++.h>
using namespace std;

// O(n^2) TLE
class Solution_ {
    int bs(const vector<string>& ideas, char ch){
        int st = 0, en = ideas.size() - 1;

        int idx = en;
        while(st < en){
            int mid = st + (en - st) / 2;
            if(ideas[mid][0] <= ch)
                st = mid + 1;
            else
                en = mid - 1, idx = mid;
        }

        return idx;
    }

public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> set = unordered_set<string>(ideas.begin(), ideas.end());

        int n = ideas.size();
        sort(ideas.begin(), ideas.end());

        long long res = 0;
        for(int i = 0; i < n; ++i){
            char ch = ideas[i][0];

            for(int j = bs(ideas, ch); j < n; ++j){
                string a = ideas[i];
                string b = ideas[j];

                swap(a[0], b[0]);
                if(!set.count(a) && !set.count(b))
                    res += 2;
            }
        }

        return res;
    }
};


// O(n)
class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_map<char,unordered_set<string>> groups;
        for(auto &idea : ideas)
            groups[idea[0]].insert(idea.substr(1));

        long long res = 0;
        for(auto [ch1, set1] : groups){
            for(auto [ch2, set2] : groups){
                if(ch1 == ch2) continue;

                int intersect = 0;
                for(auto idea : set1)
                    exists += set2.count(idea);

                int a = set1.size() - intersect;
                int b = set2.size() - intersect;

                res += (a * b);
            }
        }

        return res;
    }
};

int main(){

    return 0;
}
