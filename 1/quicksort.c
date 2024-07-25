#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

double benchmark(int arr[], int n, void* func(int arr[], int n))
{
    clock_t start, end;
    double time_spent;
    start = clock();
    func(arr, n);
    end = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    return time_spent;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void randomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

void asc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i;
    }
}

void desc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = n - i;
    }
}

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