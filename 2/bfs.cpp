#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, vector<int>> &graph, int node, vector<int> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        ans.push_back(curr);
        for (auto i : graph[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> visited(n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bfs(graph, i, visited, ans);
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
