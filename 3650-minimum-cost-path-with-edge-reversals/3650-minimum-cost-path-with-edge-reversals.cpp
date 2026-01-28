



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);

        // Build graph
        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w});        // normal edge
            graph[v].push_back({u, 2 * w});    // reversed edge
        }

        // Dijkstra
        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<>
        > pq;

        pq.push({0, 0}); // {cost, node}

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node]) continue;

            for (auto &[next, w] : graph[node]) {
                if (dist[next] > cost + w) {
                    dist[next] = cost + w;
                    pq.push({dist[next], next});
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? -1 : dist[n - 1];
    }
};
