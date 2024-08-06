#include <stdio.h>

typedef enum { false, true } bool;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

bool unique(int arr[], int n)
{
    // The next line just sorts the array with inbuild function, I don't know 
    // if we are allowed to use it in lab, so if they don't allow, use merge sort.
    qsort(arr, n, sizeof(int), compare);
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] == arr[i + 1])
            return false;
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