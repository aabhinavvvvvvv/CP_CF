#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));
        unordered_map<int, long long> main_diag, anti_diag;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
                main_diag[i - j] += a[i][j];
                anti_diag[i + j] += a[i][j];
            }
        }

        long long max_sum = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                long long current = main_diag[i - j] + anti_diag[i + j] - a[i][j];
                max_sum = max(max_sum, current);
            }
        }

        cout << max_sum << '\n';
    }

    return 0;
}
