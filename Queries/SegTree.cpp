#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
 
using namespace std;
 
const int MAXN = 200000; // Ajusta según el tamaño de tu problema
int segTree[4 * MAXN];
int arr[MAXN];
 
void build(int idx, int l, int r)
{
    if (l == r)
    {
        segTree[idx] = arr[l];
    }
    else
    {
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);
        segTree[idx] = min(segTree[2 * idx], segTree[2 * idx + 1]);
    }
}
 
int query(int idx, int l, int r, int L, int R)
{
    if (L > r || R < l)
        return INT_MAX;
    if (l >= L && r <= R)
        return segTree[idx];
    int mid = (l + r) / 2;
    int left = query(2 * idx, l, mid, L, R);
    int right = query(2 * idx + 1, mid + 1, r, L, R);
    return min(left, right);
}
 
void update(int idx, int l, int r, int low, int high, int v)
{
    if (low > r || high < l)
        return;
    if (l == r)
    {
        segTree[idx] = v;
        return;
    }
    int mid = (l + r) / 2;
    update(2 * idx, l, mid, low, high,v);
    update(2 * idx + 1, mid + 1, r, low, high,v);
    segTree[idx] = min(segTree[idx * 2] ,segTree[idx * 2 + 1]);
}
 
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q; 
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
 
    build(1, 0, n - 1);
 
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int k, v;
            cin >> k >> v;
            k--;
            update(1, 0, n - 1, k, k, v);
        }
        else
        {
            int L, R;
            cin >> L >> R;
            cout << query(1, 0, n - 1, L - 1, R - 1) << "\n";
        }
    }
 
    return 0;
}