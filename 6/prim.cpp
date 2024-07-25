#include <bits/stdc++.h>
using namespace std;

void prim(vector<vector<pair<int, int> > > graph, int V) {
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> mstSet(V, false);
    key[0] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!mstSet[i] && (u == -1 || key[i] < key[u])) {
                u = i;
            }
        }
        mstSet[u] = true;
        for (auto i : graph[u]) {
            int v = i.first;
            int weight = i.second;
            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " " << key[i] << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<vector<pair<int, int> > > graph(V);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    prim(graph, V);
    return 0;
}