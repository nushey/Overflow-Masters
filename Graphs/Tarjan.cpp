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
            low[u] = min(low[u], low[v]);
            if (low[v] >= disc[u] && parent != -1)
            {
                if (!ap[u])
                    ap[u] = true;
            }
        }
        else if (v != parent)
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    if (parent == -1 && children > 1)
    {
        if (!ap[u])
            ap[u] = true;
    }
}
