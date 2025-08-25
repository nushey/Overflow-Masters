void solve() {
    vec<int> prices(n);
    vec<int> pages(n);
    vec<vec<int>> dp(n + 1, vec<int>(x + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= x; j++) {
            if (prices[i] <= j) {
                dp[i + 1][j] = max(dp[i][j], pages[i] + dp[i][j - prices[i]]);
            } else {
                dp[i + 1][j] = dp[i][j];
            }
        }
    }
}
