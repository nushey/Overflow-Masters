#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

vector<vector<int>> g;
vector<bool> visited;
vector<int> disc; // Discovery times of visited vertices
vector<int> low;  // Lowest points reachable
vector<bool> ap;  // Articulation points
int times = 0;

void DFS(int u, int parent)
{
    visited[u] = true;
    disc[u] = low[u] = ++times;
    int children = 0;
    for (int v : g[u])
    {
        if (!visited[v])
        {
            children++;
            DFS(v, u);
            // Check if the subtree rooted at v has a connection back to one of the ancestors of u
            low[u] = min(low[u], low[v]);
            // u is an articulation point if the lowest vertex reachable from subtree under v is below u in DFS tree
            if (low[v] >= disc[u] && parent != -1)
            {
                if (!ap[u])
                ap[u] = true;
            }
        }
        else if (v != parent)
        { // Update low value of u for parent function calls
            low[u] = min(low[u], disc[v]);
        }
    }
    // Root node is an articulation point if it has two or more children
    if (parent == -1 && children > 1)
    {
        if (!ap[u])
        ap[u] = true;
    }
}
