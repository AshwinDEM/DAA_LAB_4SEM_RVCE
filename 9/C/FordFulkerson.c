#include <stdio.h>

// Ford Fulkerson Algorithm in C

typedef enum { false, true } bool;

bool bfs(int rGraph[6][6], int s, int t, int parent[])
{
    bool visited[6] = {0};
    int queue[6];
    int front = -1;
    int rear = -1;
    int queue_element;
    int u;
    visited[s] = true;
    queue[++rear] = s;
    parent[s] = -1;

    while (front != rear)
    {
        queue_element = queue[++front];
        for (u = 0; u < 6; u++)
        {
            if (visited[u] == false && rGraph[queue_element][u] > 0)
            {
                queue[++rear] = u;
                parent[u] = queue_element;
                visited[u] = true;
            }
        }
    }

    return (visited[t] == true);
}

int fordFulkerson(int graph[6][6], int s, int t)
{
    int u, v;
    int rGraph[6][6];
    for (u = 0; u < 6; u++)
        for (v = 0; v < 6; v++)
            rGraph[u][v] = graph[u][v];

    int parent[6];
    int max_flow = 0;

    while (bfs(rGraph, s, t, parent))
    {
        int path_flow = 9999;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = path_flow < rGraph[u][v] ? path_flow : rGraph[u][v];
        }

        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main()
{
    int graph[6][6] = {{0, 16, 13, 0, 0, 0},
                       {0, 0, 10, 12, 0, 0},
                       {0, 4, 0, 0, 14, 0},
                       {0, 0, 9, 0, 0, 20},
                       {0, 0, 0, 7, 0, 4},
                       {0, 0, 0, 0, 0, 0}};

    printf("The maximum possible flow is %d\n", fordFulkerson(graph, 0, 5));
    return 0;
}