// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label
#include <bits/stdc++.h>
using namespace std;

class Solution { // O(26 * n)
    vector<int> count;
    vector<vector<int>> graph;

    vector<int> countLabels(int node, int parent, const string &labels){
        vector<int> curCount(26,0);
        count[node] = 1;

        for(auto &neigh : graph[node]){
            if(neigh == parent) continue;

            vector<int> childCount = countLabels(neigh,node,labels);

            ++curCount[labels[neigh] - 'a'];
            for(int i = 0; i < 26; ++i)
                curCount[i] += childCount[i];
        }

        count[node] += curCount[labels[node] - 'a'];
        return curCount;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        count.resize(n,0);

        for(auto &edge : edges){
            int from = edge[0], to = edge[1];
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        countLabels(0, -1, labels);
        return count;
    }
};

int main(){

    return 0;
}
