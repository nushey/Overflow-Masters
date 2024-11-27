#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
#define MOD 1000000007
using namespace std;


void solve() {
    int n; 
    int x; 
    vector<int> prices(n); 
    vector<int> pages(n); 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));

    for(int i = 0; i < n; i++) {  
        for(int j = 0; j <= x; j++) {  
            if(prices[i] <= j) {
                // If the price of book i is less than or equal to budget j,
                // we have two options:
                // 1. Do not take book i: dp[i+1][j] = dp[i][j]
                // 2. Take book i: dp[i+1][j] = pages of book i + dp[i][j - price of book i]
                dp[i+1][j] = max(dp[i][j], pages[i] + dp[i][j - prices[i]]);
            } else {
                // If we cannot afford book i with budget j, simply
                // copy the value of the solution without this book
                dp[i+1][j] = dp[i][j];
            }
        }
    }
}
