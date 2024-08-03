#include <bits/stdc++.h>
using namespace std;

// Job assignment problem using branch and bound

void assignment(vector<vector<int>> mat)
{
    int n = mat.size();
    vector<int> assigned(n, -1);
    int cost = 0;
    int mincost = 0;
    int mincostindex = 0;
    int i = 0;
    while (i < n)
    {
        int j = 0;
        while (j < n)
        {
            if (assigned[j] == -1)
            {
                cost += mat[i][j];
                if (cost < mincost || mincost == 0)
                {
                    mincost = cost;
                    mincostindex = j;
                }
                cost -= mat[i][j];
            }
            j++;
        }
        assigned[mincostindex] = i;
        cost += mat[i][mincostindex];
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Worker " << i << " assigned to job " << assigned[i] << endl;
    }
    cout << "Total cost: " << cost << endl;
}

int main()
{
    vector<vector<int>> mat = {
        {9, 2, 7, 8},
        {6, 4, 3, 7},
        {5, 8, 1, 8},
        {7, 6, 9, 4}
    };
    assignment(mat);
    return 0;
}