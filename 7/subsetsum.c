#include <stdio.h>

void subsetsum(int set[], int n, int sum)
{
    int subset[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        subset[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        subset[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < set[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
            else
            {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            }
        }
    }
    if (subset[n][sum] == 1)
    {
        printf("The sum %d can be obtained from the set\n", sum);
    }
    else
    {
        printf("The sum %d cannot be obtained from the set\n", sum);
    }
}

int main()
{
    int n, sum;
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    int set[n];
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &set[i]);
    }
    printf("Enter the sum to be checked: ");
    scanf("%d", &sum);
    subsetsum(set, n, sum);
    return 0;
}