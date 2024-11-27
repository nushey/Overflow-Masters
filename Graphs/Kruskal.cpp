#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

const int MAX = 20000;

struct Edge {
    int u, v;  // Vértices que conecta la arista
    int weight;  // Peso de la arista

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int parent[MAX];
int setSize[MAX];

// Función para encontrar el representante de un conjunto usando compresión de caminos
int find(int u) {
    if (parent[u] != u) {
        parent[u] = find(parent[u]);  // Compresión de caminos
    }
    return parent[u];
}
// Función para unir dos conjuntos usando unión por size
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        // Unión por rango
        if (setSize[rootU] > setSize[rootV]) {
            parent[rootV] = rootU;
            setSize[rootU] += setSize[rootV];
        } else {
            parent[rootU] = rootV;
            setSize[rootV] += setSize[rootU];
        } 
    }
}

long long kruskal(int V, vector<Edge>& edges, long& elements) {
    // Inicializar los representantes y rangos
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        setSize[i] = 1;
    }

    // Ordenar las aristas por peso
    sort(edges.begin(), edges.end());

    long long mst_weight = 0;
    for (const auto& edge : edges) {
        if (find(edge.u) != find(edge.v)){
            mst_weight += edge.weight;
            unionSets(edge.u, edge.v);
            elements--;
        }
    }
    return mst_weight;
}