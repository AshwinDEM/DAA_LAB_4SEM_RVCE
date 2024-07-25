#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(unordered_map<int, vector<int>> &graph, int node, vector<int> &visited, vector<int> &ans)
{
    visited[node] = 1;
    for (auto i : graph[node])
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, ans);
        }
    }
    ans.push_back(node);
}

vector<int> topographicalsortDFS(unordered_map<int, vector<int>>& graph, int n)
{
    vector<int> visited(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(graph, i, visited, ans);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}



int main()
{

}