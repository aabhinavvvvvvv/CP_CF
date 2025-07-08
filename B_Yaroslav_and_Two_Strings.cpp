#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

ll solveMem(string& s, string& t, int n, int i, bool gS, bool gT, vector<vector<vector<int>>>& dp) {
    if (i == n) {
        return (gS && gT) ? 1 : 0;
    }
    if (dp[i][gS][gT] != -1) return dp[i][gS][gT];

    ll ways = 0;
    if (s[i] != '?' && t[i] != '?') {
        if (s[i] > t[i])
            ways = solveMem(s, t, n, i + 1, true, gT, dp);
        else if (s[i] < t[i])
            ways = solveMem(s, t, n, i + 1, gS, true, dp);
        else
            ways = solveMem(s, t, n, i + 1, gS, gT, dp);
    } else if (s[i] == '?' && t[i] == '?') {
        // Equal pairs (0-0, 1-1, ..., 9-9) → 10 options
        ways += 10 * solveMem(s, t, n, i + 1, gS, gT, dp);
        ways %= MOD;

        // s > t → pairs (1,0), (2,0)...(9,8): 45 pairs
        ways += 45 * solveMem(s, t, n, i + 1, true, gT, dp);
        ways %= MOD;

        // s < t → pairs (0,1), ..., (8,9): 45 pairs
        ways += 45 * solveMem(s, t, n, i + 1, gS, true, dp);
        ways %= MOD;
    } else if (s[i] == '?') {
        int d = t[i] - '0';

        // s < t
        ways += d * solveMem(s, t, n, i + 1, gS, true, dp);
        ways %= MOD;

        // s > t
        ways += (9 - d) * solveMem(s, t, n, i + 1, true, gT, dp);
        ways %= MOD;

        // s == t
        ways += solveMem(s, t, n, i + 1, gS, gT, dp);
        ways %= MOD;
    } else if (t[i] == '?') {
        int d = s[i] - '0';

        // t < s
        ways += d * solveMem(s, t, n, i + 1, true, gT, dp);
        ways %= MOD;

        // t > s
        ways += (9 - d) * solveMem(s, t, n, i + 1, gS, true, dp);
        ways %= MOD;

        // s == t
        ways += solveMem(s, t, n, i + 1, gS, gT, dp);
        ways %= MOD;
    }

    return dp[i][gS][gT] = ways;
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, -1)));

    cout << solveMem(s, t, n, 0, false, false, dp) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
