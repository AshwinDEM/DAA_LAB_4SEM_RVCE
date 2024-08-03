#include <bits/stdc++.h>
using namespace std;

void tsp(vector<vector<int>> &graph, vector<int> &path, vector<int> &visited, int curr, int n, int count, int cost, int &ans)
{
    if (count == n && graph[curr][0])
    {
        ans = min(ans, cost + graph[curr][0]);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && graph[curr][i])
        {
            visited[i] = 1;
            path.push_back(i);
            tsp(graph, path, visited, i, n, count + 1, cost + graph[curr][i], ans);
            visited[i] = 0;
            path.pop_back();
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    vector<int> path;
    vector<int> visited(n, 0);
    visited[0] = 1;
    path.push_back(0);
    int ans = INT_MAX;
    tsp(graph, path, visited, 0, n, 1, 0, ans);
    cout << ans << endl;
    return 0;
}