#include <stdio.h>

void dijkstra(int n, int graph[10][10], int src)
{
    int dist[10], visited[10], count, min, next;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = graph[src][i];
        visited[i] = 0;
    }
    dist[src] = 0;
    visited[src] = 1;
    count = 1;
    while (count < n - 1)
    {
        min = 999;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] < min && !visited[i])
            {
                min = dist[i];
                next = i;
            }
        }
        visited[next] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (min + graph[next][i] < dist[i])
                {
                    dist[i] = min + graph[next][i];
                }
            }
        }
        count++;
    }
    printf("The shortest path from the source vertex %d to all other vertices is:\n", src);
    for (int i = 1; i <= n; i++)
    {
        if (i != src)
        {
            printf("Source: %d, Destination: %d, Cost: %d\n", src, i, dist[i]);
        }
    }
}

int main()
{
    int n, graph[10][10], src;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &src);
    dijkstra(n, graph, src);
    return 0;
}