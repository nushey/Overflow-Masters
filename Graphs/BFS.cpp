#include <bits/stdc++.h>

using namespace std;

// Adjacency list
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

// Adjacency matrix
void bfs(vector<vector<char>> &g, int x, int y){
    vector<vector<bool>> visited(g.size(), vector<bool> (g[0].size(), false));
    visited[x][y] = true;
    int dx[] = {1,-1,0,0};
    int dy[] = {0, 0, 1, -1};
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = node.first + dx[i];
            int ny = node.second + dy[i];
            if(nx < g.size() && ny < g[0].size() && g[nx][ny] != '#' && !visited[nx][ny]){
                q.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }
}
