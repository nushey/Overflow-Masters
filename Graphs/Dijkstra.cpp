#include <bits/stdc++.h>

using namespace std;

#define ll long long

void dijkstra(const vector<vector<pair<int, ll>>> &graph, int start, vector<ll> &distances) {
    distances[start] = 0;

    // Priority queue that stores pairs {cost, node}
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, start}); 

    while (!pq.empty()) {

        ll currentCost = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        // If we have already found a shorter path before, skip it
        if (currentCost > distances[currentNode]) continue;

        for (const auto &neighbor : graph[currentNode]) {
            int neighborNode = neighbor.first;
            ll edgeWeight = neighbor.second;
            ll newCost = currentCost + edgeWeight;

            // If we find a shorter path to the neighbor, update it
            if (newCost < distances[neighborNode]) {
                distances[neighborNode] = newCost;
                pq.push({newCost, neighborNode});
            }
        }
    }
}