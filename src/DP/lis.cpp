int lis(vec<int>& arr) {
    int n = arr.size();
    vec<int> lis(n, 1);
    for (int i = 1; i < n; i++) {
        for (int prev = 0; prev < i; prev++) {
            if (arr[i] > arr[prev] && lis[i] < lis[prev] + 1) {
                lis[i] = lis[prev] + 1;
            }
        }
    }
    return *max_element(lis.begin(), lis.end());
}