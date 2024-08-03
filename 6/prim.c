#include <stdio.h>

void prim(int n, int cost[10][10])
{
    int u, v, min, mincost = 0, ne = 1;
    int visited[10] = {0};
    visited[1] = 1;
    while (ne < n)
    {
        for (int i = 1, min = 999; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (cost[i][j] < min)
                {
                    if (visited[i] != 0)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if (visited[u] == 0 || visited[v] == 0)
        {
            printf("Edge %d: (%d, %d) cost: %d\n", ne++, u, v, min);
            mincost += min;
            visited[v] = 1;
        }
        cost[u][v] = cost[v][u] = 999;
    }
    printf("Minimum cost = %d\n", mincost);
}

int main()
{
    int n, cost[10][10];
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    prim(n, cost);
    return 0;
}