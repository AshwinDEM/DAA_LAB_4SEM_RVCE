#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void quicksort(int arr[], int n)
{
    if (n > 1)
    {
        int pivot = arr[n / 2];
        int i = 0;
        int j = n - 1;
        while (i <= j)
        {
            while (arr[i] < pivot)
            {
                i++;
            }
            while (arr[j] > pivot)
            {
                j--;
            }
            if (i <= j)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        quicksort(arr, j + 1);
        quicksort(arr + i, n - i);
    }
}

int main()
{
    int arr[1000], n = 1000;
    randomarray(arr, n);
    printArray(arr, n);
    quicksort(arr, n);
    printArray(arr, n);

}