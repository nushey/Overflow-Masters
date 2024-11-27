#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int lis(vector<int>& arr)
{
    int n = arr.size();
    vector<int> lis(n, 1);

    // Compute optimized LIS values in
    // bottom-up manner
    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
                lis[i] = lis[prev] + 1;
            }
        }
    }

    // Return maximum value in lis
    return *max_element(lis.begin(), lis.end());
}