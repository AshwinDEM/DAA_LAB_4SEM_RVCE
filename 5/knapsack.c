#include <stdio.h>

void knapsack(int n, int w, int* wt, int* val)
{
    int result[10][10];
    int K[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
            {
                K[i][j] = 0;
            }
            else if (wt[i - 1] <= j)
            {
                K[i][j] = (val[i - 1] + K[i - 1][j - wt[i - 1]]) > K[i - 1][j] ? (val[i - 1] + K[i - 1][j - wt[i - 1]]) : K[i - 1][j];
            }
            else
            {
                K[i][j] = K[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            result[i][j] = K[i][j];
        }
    }

    printf("The included items are: ");
    int i = n, j = w;
    while (i > 0 && j > 0)
    {
        if (result[i][j] != result[i - 1][j])
        {
            printf("%d ", i);
            j -= wt[i - 1];
            i--;
        }
        else
        {
            i--;
        }
    }
    printf("\n");
}

int main()
{
    int n, w;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &wt[i]);
    }
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &val[i]);
    }
    printf("Enter the maximum weight: ");
    scanf("%d", &w);
    knapsack(n, w, wt, val);
    
    return 0;
}