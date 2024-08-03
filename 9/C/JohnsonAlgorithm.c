#include <stdio.h>
#include <limits.h>

// Johnson Algorithm in C

#define INF INT_MAX

int min(int a, int b)
{
    return a < b ? a : b;
}

void johnson(int graph[5][5])
{
    int i, j, k;
    int dist[5][5];

    for (i = 0; i < 5; i++)
        for (j = 0; j < 5; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < 5; k++)
    {
        for (i = 0; i < 5; i++)
        {
            for (j = 0; j < 5; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[5][5] = {
        {0, 3, INF, 5, 8},
        {INF, 0, 2, INF, INF},
        {INF, INF, 0, 7, INF},
        {2, INF, INF, 0, 1},
        {INF, INF, INF, INF, 0}};

    johnson(graph);
    return 0;
}

