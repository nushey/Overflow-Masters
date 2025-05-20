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
        int fatherA = find(a);#include <bits/stdc++.h>

        using namespace std;
        
        typedef vector<int> vi;
        
        
        class UFDS{
            private:
                vi p, rank, setSize;
                int numSets;
            public:
                UFDS(int N){
                    p.assign(N,0); for(int i = 0; i < N; i++) p[i] = i;
                    rank.assign(N,0);
                    setSize.assign(N, 1);
                    numSets = N;
                }
                int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i]));}
                bool isSameSet(int i, int j) { return findSet(i) == findSet(j);}
                int numDisjointSets() { return numSets;}
                int sizeOfSet(int i) { return setSize[findSet(i)];}
                void unionSet(int i, int j){
                    if(isSameSet(i,j)) return;
                    int x = findSet(i), y = findSet(j);
                    if(rank[x] > rank[y]) swap(x,y);
                    p[x] = y;
                    if(rank[x] == rank[y]) ++rank[y];
                    setSize[y] += setSize[x];
                    --numSets;
                }
        };
        
        
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