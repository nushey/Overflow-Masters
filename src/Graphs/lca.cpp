void dfs(int u, int p, vec<vec<int>>& memo, vec<int>& lev, int log, vec<vec<int>>& g){
    memo[u][0] = p;
    LI(i, 1, log) memo[u][i] = memo[memo[u][i-1]][i-1];
    for (int v : g[u]){
        if (v != p){
            lev[v] = lev[u] + 1;
            dfs(v, u, memo, lev, log, g);
        }
    }
}

int lca (int u, int v, int log, vec<int>& lev, vec<vec<int>>& memo){
    if (lev[u] < lev[v]) swap(u, v);
    RI(i, log, 0){
        if ((lev[u] - pow(2, i)) >= lev[v])
            u = memo[u][i];
    }
    if (u == v) return u;
    RI(i, log, 0){
        if (memo[u][i] != memo[v][i]){
            u = memo[u][i];
            v = memo[v][i];
        }
    }
    return memo[u][0];
}

void solve()
{
    int n, q;
    vec<vec<int>> g (n, vec<int>());
    int log = ceil(log2(n));
    vec<vec<int>> memo (n, vec<int>(log+1, -1));
    vec<int> lev(n);
    dfs(0, 0, memo, lev, log, g);
}
