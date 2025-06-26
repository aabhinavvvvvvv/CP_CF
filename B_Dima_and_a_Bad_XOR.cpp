/*
 * Competitive Programming Template
 * Author: Abhinav Gupta
 * GitHub: @aabhinavvvvvvv
 * MAHAKAL KI JAI
 */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;

const int MAXN = 505;
const int MAXXOR = 1025; // max XOR value based on constraint (0 ≤ a[i][j] ≤ 1023)

int n, m;
vvi a;
vector<vector<int>> memo; // -1 = unvisited, 0 = false, 1 = true
vector<vector<int>> path; // to store choice (column index) at each step

bool solveMem(int i, int xor_val) {
    if (i == n) return xor_val > 0;
    if (memo[i][xor_val] != -1) return memo[i][xor_val];

    for (int j = 0; j < m; ++j) {
        int new_xor = xor_val ^ a[i][j];
        if (solveMem(i + 1, new_xor)) {
            path[i][xor_val] = j;
            return memo[i][xor_val] = 1;
        }
    }
    return memo[i][xor_val] = 0;
}

void solve() {
    cin >> n >> m;
    a.assign(n, vi(m));
    memo.assign(n + 1, vector<int>(MAXXOR, -1));
    path.assign(n, vector<int>(MAXXOR, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];

    if (!solveMem(0, 0)) {
        cout << "NIE\n";
        return;
    }

    // Reconstruct path
    cout << "TAK\n";
    int xor_val = 0;
    for (int i = 0; i < n; ++i) {
        int col = path[i][xor_val];
        cout << col + 1 << " ";
        xor_val ^= a[i][col];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
 