#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<int>> graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> visited(V, false);
    
    for (int i = 0; i < V - 1; i++) {
        // int u = -1;
        // for (int j = 0; j < V; j++) {
        //     if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
        //         u = j;
        //     }
        // }
        int u = min_element(dist.begin(), dist.end()) - dist.begin();
        visited[u] = true;
        for (int j = 0; j < V; j++) {
            if (!visited[j] && graph[u][j]) {// && dist[u] != INT_MAX && dist[u] + graph[u][j] < dist[j]) {
                dist[j] = std::min(dist[j], dist[u] + graph[u][j]);
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
    vector<vector<int> > graph(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int src;
    cin >> src;
    dijkstra(graph, src);
    return 0;
}