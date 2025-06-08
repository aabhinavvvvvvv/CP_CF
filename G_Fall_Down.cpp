#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        for (int j = 0; j < m; j++) {
            int fallTo = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (grid[i][j] == 'o') {
                    fallTo = i - 1;
                } else if (grid[i][j] == '*') {
                    grid[i][j] = '.';
                    grid[fallTo][j] = '*';
                    fallTo--;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
