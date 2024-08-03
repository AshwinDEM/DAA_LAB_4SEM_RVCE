#include <bits/stdc++.h>
using namespace std;

// Longest common subsequence using dynamic programming
int LCS(vector<int> a, vector<int> b)
{
    int m = a.size();
    int n = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> b = {1, 3, 5, 7, 9};
    cout << LCS(a, b);
    return 0;
}