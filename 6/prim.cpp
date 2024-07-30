#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
    bool operator<(const edge &e) {
        return w < e.w;
    }
};

int find(vector<int> &parent, int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

void Union(vector<int> &parent, int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

void prim(vector<edge> &edges, int V) {
    sort(edges.begin(), edges.end());
    vector<int> parent(V, -1);
    vector<edge> result;
    int i = 0, e = 0;
    while (e < V - 1) {
        edge next_edge = edges[i++];
        int x = find(parent, next_edge.u);
        int y = find(parent, next_edge.v);
        if (x != y) {
            result.push_back(next_edge);
            Union(parent, x, y);
            e++;
        }
    }
    for (auto i : result) {
        cout << i.u << " - " << i.v << " " << i.w << endl;
    }
}

int main() {
    int V, E;
    cin >> V >> E;
    vector<edge> edges;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    prim(edges, V);
    return 0;
}