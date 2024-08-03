#include <stdio.h>

typedef enum { false, true } bool;

bool unique(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (unique(arr, n))
        printf("All elements are unique\n");
    else
        printf("Array contains duplicate elements\n");
    return 0;
}