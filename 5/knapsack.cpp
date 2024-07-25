#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

void knapsack(int n, int W, vector<int> wt, vector<int> val) {
    vector<vector<int> > K(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            } else {
                K[i][w] = K[i - 1][w];
            }
        }
    }
    result.resize(n + 1, vector<int>(W + 1, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            result[i][j] = K[i][j];
        }
    }

    cout << "The included items are: ";
    int i = n, j = W;
    while (i > 0 && j > 0) {
        if (K[i][j] != K[i - 1][j]) {
            cout << i << " ";
            j -= wt[i - 1];
            i--;
        } else {
            i--;
        }
    }
    cout << endl;
}

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> wt(n), val(n);
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    knapsack(n, W, wt, val);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}