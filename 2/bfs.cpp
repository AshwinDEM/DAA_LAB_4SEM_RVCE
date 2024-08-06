#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

void bfs(unordered_map<int, vector<int>>& graph, int start, vector<int>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

bool isConnected(unordered_map<int, vector<int>>& graph, int n) {
    vector<int> visited(n + 1, 0);
    bfs(graph, 1, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false; // Graph is not connected
        }
    }
    return true; // Graph is connected
}

int main() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    if (isConnected(graph, n)) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}