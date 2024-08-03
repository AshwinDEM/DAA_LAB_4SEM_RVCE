#include <bits/stdc++.h>
using namespace std;

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    quicksort(arr, 0, arr.size() - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}