#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> disc;               // Discovery times of visited vertices
vector<int> low;                // Lowest points reachable
vector<pair<int, int>> bridges; // Vector to store bridges
int times = 0;

void DFS(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++times;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            // If the lowest vertex reachable from subtree under v is below u in DFS tree, then u - v is a bridge
            if (low[v] > disc[u])
            {
                bridges.emplace_back(min(u, v), max(u, v)); // Store the bridge
            }
        }
        else if (v != parent)
        { // Update low value of u for parent function calls
            low[u] = min(low[u], disc[v]);
        }
    }
}
