#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

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

void mergesort(int arr[], int n)
{
    if (n > 1)
    {
        int mid = n / 2;
        int left[mid];
        int right[n - mid];
        for (int i = 0; i < mid; i++)
        {
            left[i] = arr[i];
        }
        for (int i = mid; i < n; i++)
        {
            right[i - mid] = arr[i];
        }
        mergesort(left, mid);
        mergesort(right, n - mid);
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < mid && j < n - mid)
        {
            if (left[i] < right[j])
            {
                arr[k] = left[i];
                i++;
            }
            else
            {
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        while (i < mid)
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        while (j < n - mid)
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
}

int main()
{
    int arr[1000], n = 1000;
    randomarray(arr, n);
    printArray(arr, n);
    mergesort(arr, n);
    printArray(arr, n);

}