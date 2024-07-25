#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > result;

void floyd(int n) {
    result.resize(n, vector<int>(n, 0));
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = std::min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> result[i][j];
        }
    }
    floyd(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}