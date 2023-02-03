// https://leetcode.com/problems/cheapest-flights-within-k-stops/
#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    const int INF = 1e5;
    vector<vector<pair<int,int>>> graph(n);

    for(auto& flight : flights){
        int from = flight[0], to = flight[1], price = flight[2];
        graph[from].push_back({to,price});
    }

    int stops = 0;
    vector<int> dist(n, INF);
    queue<pair<int,int>> ready;

    ready.push({src,0});
    while(!ready.empty() && stops <= k){
        for(int sz = ready.size(); sz; --sz){
            auto [node, curPrice] = ready.front(); ready.pop();

            for(auto& [neig, newPrice] : graph[node]){
                int totalPrice = curPrice + newPrice;
                if(dist[neig] >  totalPrice){
                    ready.push({neig, totalPrice});
                    dist[neig] = totalPrice;
                }
            }
        }
        ++stops;
    }

    return (dist[dst] == INF) ? -1 : dist[dst];
}

int main(){

    return 0;
}
