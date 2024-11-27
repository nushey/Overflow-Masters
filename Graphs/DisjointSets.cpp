#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const int tam = 20000;

vector<int> father(tam);
vector<int> sizes(tam, 1);

int find(int node) {
    if (father[node] != node) {
        father[node] = find(father[node]);
    }
    return father[node];
};

void unions(int a, int b) {
    if (sizes[a] > sizes[b]) {
        father[b] = a;
        sizes[a] += sizes[b];
    }
    else {
        father[a] = b;
        sizes[b] += sizes[a];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
    int groups = n;
    int maxSize = 1;
    while (m-- > 0) {
        int a, b; cin >> a >> b;
        int fatherA = find(a);
        int fatherB = find(b);
        if (fatherA != fatherB) {
            unions(fatherA, fatherB);
            maxSize = max(maxSize, sizes[find(fatherA)]);
            groups--;
        }
        cout << groups << " " << maxSize << endl;
    }
    return 0;
}