#include <bits/stdc++.h>
using namespace std;

bool unique(vector<int> arr)
{
    // The next line just sorts the array with inbuild function, I don't know 
    // if we are allowed to use it in lab, so if they don't allow, use merge sort.
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            return false;
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1};
    if (unique(arr))
        cout << "All elements are unique\n";
    else
        cout << "Array contains duplicate elements\n";
    return 0;
}