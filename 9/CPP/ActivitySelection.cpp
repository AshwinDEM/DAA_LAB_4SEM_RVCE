#include <bits/stdc++.h>
using namespace std;

// Activity Selection

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void activitySelection(vector<pair<int, int>> &activities)
{
    sort(activities.begin(), activities.end(), compare);
    int n = activities.size();
    int i = 0;
    cout << "Following activities are selected: ";
    cout << "(" << activities[i].first << ", " << activities[i].second << "), ";
    for (int j = 1; j < n; j++)
    {
        if (activities[j].first >= activities[i].second)
        {
            cout << "(" << activities[j].first << ", " << activities[j].second << "), ";
            i = j;
        }
    }
}

int main()
{
    vector<pair<int, int>> activities = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    activitySelection(activities);
    return 0;
}

