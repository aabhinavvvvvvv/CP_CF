#include <bits/stdc++.h>
using namespace std;

int solve(string &a, string &b, int i, int j, vector<vector<int>> &dp, int &res) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (a[i] == b[j]) {
        dp[i][j] = 1 + solve(a, b, i - 1, j - 1, dp, res);
        res = max(res, dp[i][j]);
        return dp[i][j];
    } else {
        solve(a, b, i - 1, j, dp, res);
        solve(a, b, i, j - 1, dp, res);
        return dp[i][j] = 0;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;

        int n = a.size(), m = b.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int res = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                solve(a, b, i, j, dp, res);
            }
        }

        cout << n + m - 2 * res << endl;
    }
    return 0;
}
