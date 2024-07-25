#include <bits/stdc++.h>
using namespace std;

vector<int> subsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    vector<vector<bool> > dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    vector<int> res;
    if (!dp[n][sum])
        return res;
    int i = n, j = sum;
    while (i > 0 && j > 0)
    {
        if (dp[i - 1][j])
            i--;
        else
        {
            res.push_back(arr[i - 1]);
            j -= arr[i - 1];
            i--;
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    vector<int> res = subsetSum(arr, sum);
    if (res.size() == 0)
        cout << "No subset with given sum\n";
    else
    {
        cout << "Subset with given sum: ";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    return 0;
}