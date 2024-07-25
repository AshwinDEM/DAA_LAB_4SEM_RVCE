#include <bits/stdc++.h>
#include <fstream>
using namespace std;


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

ofstream quick("quick.csv"), mergef("merge.csv");

void benchmark(std::function<void (int[], int)> func, int arr[], int n, ostream &fout)
{
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    fout << n << ",";

    auto t1 = high_resolution_clock::now(), t2 = high_resolution_clock::now();

    asc(arr, n);

    t1 = high_resolution_clock::now();
    func(arr, n);
    t2 = high_resolution_clock::now();

    duration<double, std::milli> ms_double = t2 - t1;
    cout << "Ascending = " << ms_double.count() << "ms\n";
    fout << ms_double.count() << ",";

    desc(arr, n);

    t1 = high_resolution_clock::now();
    func(arr, n);
    t2 = high_resolution_clock::now();

    ms_double = t2 - t1;
    cout << "Descending = " << ms_double.count() << "ms\n";
    fout << ms_double.count() << ",";

    randomarray(arr, n);

    t1 = high_resolution_clock::now();
    func(arr, n);
    t2 = high_resolution_clock::now();

    ms_double = t2 - t1;
    cout << "Random = " << ms_double.count() << "ms\n\n";
    fout << ms_double.count() << endl;
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
    int n;
    for (int i = 0; i < 20; i++)
    {
        n = 1 << i;
        int arr[n];
        cout << "n = " << n << endl;
        benchmark(mergesort, arr, n, mergef);
        benchmark(quicksort, arr, n, quick);
    }
}