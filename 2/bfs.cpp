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

