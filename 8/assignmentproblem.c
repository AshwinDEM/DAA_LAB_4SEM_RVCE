#include <stdio.h>
#include <stdlib.h>

// Job assigment problem using branch and bound

void assignment(int mat[4][4], int n)
{
    int assigned[n];
    for (int i = 0; i < n; i++)
    {
        assigned[i] = -1;
    }
    int cost = 0;
    int mincost = 0;
    int mincostindex = 0;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            if (assigned[j] == -1)
            {
                cost += mat[i][j];
                if (cost < mincost || mincost == 0)
                {
                    mincost = cost;
                    mincostindex = j;
                }
                cost -= mat[i][j];
            }
            j++;
        }
        assigned[mincostindex] = i;
        cost += mat[i][mincostindex];
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Worker %d assigned to job %d\n", i, assigned[i]);
    }
    printf("Total cost: %d\n", cost);
}

int main()
{
    int mat[4][4] = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    assignment(mat, 4);
    return 0;
}