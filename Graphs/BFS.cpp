void bfs(vector<vector<int>> &g, int start){
    vector<bool> visited(g.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()){
        int n = q.front();
        q.pop();
        for (int neighbor : g[n]){
            if (!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}