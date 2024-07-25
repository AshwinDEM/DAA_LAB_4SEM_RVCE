#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<pair<int, int> > > graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    set<pair<int, int> > s;
    s.insert({0, src});
    while (!s.empty()) {
        pair<int, int> p = *s.begin();
        s.erase(s.begin());
        int u = p.second;
        for (auto i : graph[u]) {
            int v = i.first;
            int weight = i.second;
            if (dist[v] > dist[u] + weight) {
                if (dist[v] != INT_MAX) {
                    s.erase(s.find({dist[v], v}));
                }
                dist[v] = dist[u] + weight;
                s.insert({dist[v], v});
            }
        }
    }
    for (int i = 0; i < V; i++) {
        cout << i << " " << dist[i] << endl;
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
    int src;
    cin >> src;
    dijkstra(graph, src);
    return 0;
}