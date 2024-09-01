#include <bits/stdc++.h>
using namespace std;

// Implementing the subset sum problem using backtracking

void subsetSumHelper(vector<int>& arr, int sum, int start, vector<int>& path, vector<vector<int>>& result) {
    if (sum == 0) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < arr.size(); i++) {
        if (arr[i] > sum) continue; // Skip if the current element is greater than the remaining sum
        path.push_back(arr[i]);
        subsetSumHelper(arr, sum - arr[i], i + 1, path, result); // Move to the next element
        path.pop_back(); // Backtrack
    }
}

vector<vector<int>> subsetSum(vector<int>& arr, int sum) {
    vector<vector<int>> result;
    vector<int> path;
    subsetSumHelper(arr, sum, 0, path, result);
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;

    vector<vector<int>> subsets = subsetSum(arr, sum);
    for (const auto& subset : subsets) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}