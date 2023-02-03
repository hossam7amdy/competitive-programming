// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
#include<bits/stdc++.h>
using namespace std;

/*
#Approach: DFS

#Complexity
    - Time: O(n)
    - Space: O(n)
*/

class Solution {
    const int INF = 100001;

    void dfs(vector<int>& graph, vector<int> &dist, int node, int curDist){
        if(node == -1 || dist[node] != INF) // root OR done before `cycle`
            return;

        dist[node] = curDist;
        dfs(graph, dist, graph[node], curDist+1);
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,INF), dist2(n,INF);

        dfs(edges, dist1, node1, 0);
        dfs(edges, dist2, node2, 0);

        int res = -1;
        int resDist = INF;
        for(int node = 0; node < n; ++node){
            int dist = max(dist1[node], dist2[node]);
            if(dist < resDist){
                resDist = dist;
                res = node;
            }
        }

        return res;
    }
};

int main(){

    return 0;
}
