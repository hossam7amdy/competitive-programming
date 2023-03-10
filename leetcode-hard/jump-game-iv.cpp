// https://leetcode.com/problems/jump-game-iv/
#include<bits/stdc++.h>
using namespace std;

/*
# Approach: BFS

# Complexity
    - Time: O(n)
    - Space: O(n)
*/

int minJumps(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, vector<int>> valToIndexs;
    for(int i = 0; i < arr.size(); ++i)
        valToIndexs[arr[i]].push_back(i);

    queue<int> ready;
    vector<bool> vis(n, 0);

    ready.push(0);
    vis[0] = 1;

    int steps = 0;
    while(!ready.empty()){
        for(int sz = ready.size(); sz; --sz){
            int i = ready.front(); ready.pop();

            if(i == n - 1)
                return steps;

            if(i + 1 < n && !vis[i+1]){
                vis[i + 1] = 1;
                ready.push(i + 1);
            }

            if(i - 1 >= 0 && !vis[i-1]){
                vis[i - 1] = 1;
                ready.push(i - 1);
            }

            for(auto idx : valToIndexs[arr[i]]){
                if(!vis[idx]){
                    vis[idx] = 1;
                    ready.push(idx);
                }
            }

            valToIndexs[arr[i]].clear();
        }
        ++steps;
    }

    return -1;
}

int main(){

    return 0;
}
