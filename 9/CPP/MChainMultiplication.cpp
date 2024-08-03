#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication
// I don't know if this is the correct implementation of MCM, this is what is in GFG, optimised using DP

int MCM(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 1; i < n - 1; i++)
        dp[i][i + 1] = 0;
    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i < n - l; i++)
        {
            int j = i + l;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i - 1] * arr[k] * arr[j]);
            }
        }
    }
    return dp[1][n - 1];
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 3};
    cout << MCM(arr);
    return 0;
}