#include <bits/stdc++.h>
using namespace std;

// Implementing the subset sum problem using branch and bound using recursion

vector<int> subsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<int> result;
    vector<int> path;
    int pathSum = 0;
    int index = 0;
    int totalSum = accumulate(arr.begin(), arr.end(), 0);
    sort(arr.begin(), arr.end(), greater<int>());
    while (index >= 0)
    {
        if (index >= n)
        {
            if (pathSum == sum)
            {
                result = path;
                break;
            }
            index--;
            if (index < 0)
            {
                break;
            }
            pathSum -= arr[index];
            path.pop_back();
            continue;
        }
        if (pathSum + arr[index] <= sum && pathSum + totalSum >= sum)
        {
            pathSum += arr[index];
            path.push_back(arr[index]);
            index++;
        }
        else
        {
            index++;
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    vector<int> result = subsetSum(arr, sum);
    if (result.size() == 0)
    {
        cout << "No subset found with the given sum" << endl;
    }
    else
    {
        for (auto i : result)
        {
            cout << i << " ";
        }
    }
    return 0;
}