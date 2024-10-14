#include <stdio.h>

void knapsack(int n, int w, int* wt, int* val)
{
    int K[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (j - wt[i] >= 0)
            {
                K[i][j] = (val[i] + K[i - 1][j - wt[i]]) > K[i - 1][j] ? (val[i] + K[i - 1][j - wt[i]]) : K[i - 1][j];
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }

    // Backtrack to find the included items
    printf("The included items are: ");
    int i = n, j = w;
    while (i > 0 && j > 0)
    {
        if (K[i][j] != K[i - 1][j])  // Item i is included
        {
            printf("%d ", i);
            j -= wt[i];  // Subtract weight of the included item
        }
        i--;  // Move to the previous item
    }
    printf("\n");
}

int main()
{
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n + 1], val[n + 1];
    printf("Enter the weights of the items:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter the values of the items:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter the maximum weight: ");
    scanf("%d", &w);
    knapsack(n, w, wt, val);
    
    return 0;
}