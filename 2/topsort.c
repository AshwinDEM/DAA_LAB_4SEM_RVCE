#include <stdio.h>

#define MAX_NODES 10

int index;

void dfs(int graph[MAX_NODES][MAX_NODES], int node, int visited[MAX_NODES], int ans[MAX_NODES], int n) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, i, visited, ans, n);
        }
    }
    ans[index--] = node;
}

void topologicalSortDFS(int graph[MAX_NODES][MAX_NODES], int n, int ans[MAX_NODES]) {
    int visited[MAX_NODES] = {0};
    index = n - 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(graph, i, visited, ans, n);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int graph[MAX_NODES][MAX_NODES];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int ans[MAX_NODES];

    topologicalSortDFS(graph, n, ans);

    for (int i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
