#include <stdio.h>

// Activity Selection

void activitySelection(int activities[][2], int n)
{
    int i = 0;
    printf("Following activities are selected: ");
    printf("(%d, %d), ", activities[i][0], activities[i][1]);
    for (int j = 1; j < n; j++)
    {
        if (activities[j][0] >= activities[i][1])
        {
            printf("(%d, %d), ", activities[j][0], activities[j][1]);
            i = j;
        }
    }
}

int main()
{
    int activities[][2] = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    int n = sizeof(activities) / sizeof(activities[0]);
    activitySelection(activities, n);
    return 0;
}

