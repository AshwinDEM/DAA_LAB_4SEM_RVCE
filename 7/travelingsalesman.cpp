#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<pair<int, int>>> graph;
vector<int> path;
vector<int> visited;
int ans = INT_MAX;

void tsp(int curr, int n, int count, int cost) {
    if (count == n && graph[curr].begin()->first == 0) {
        ans = min(ans, cost + graph[curr].begin()->second);
        return;
    }
    for (auto &neighbor : graph[curr]) {
        int next = neighbor.first;
        int weight = neighbor.second;
        if (!visited[next]) {
            visited[next] = 1;
            path.push_back(next);
            tsp(next, n, count + 1, cost + weight);
            visited[next] = 0;
            path.pop_back();
        }
    }
}

int main() {
    int n;
    cin >> n;
    visited.resize(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int weight;
            cin >> weight;
            if (weight != 0) {
                graph[i].push_back({j, weight});
            }
        }
    }
    visited[0] = 1;
    path.push_back(0);
    tsp(0, n, 1, 0);

    cout << "The minimum cost is: " << ans << endl;

    return 0;
}