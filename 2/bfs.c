#include <stdio.h>

void bfs(int g[100][100], int n, int start, int visited[100]) {
    int queue[100], front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;

    while (front < rear) {
        int u = queue[front++];
        for (int i = 0; i < n; i++) {
            if (g[u][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
}

int isConnected(int g[100][100], int n) {
    int visited[100] = {0};
    bfs(g, n, 0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return 0; // Graph is not connected
        }
    }
    return 1; // Graph is connected
}

int main() {
    int n;
    scanf("%d", &n);
    int g[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    if (isConnected(g, n)) {
        printf("The graph is connected.\n");
    } else {
        printf("The graph is not connected.\n");
    }

    return 0;
}