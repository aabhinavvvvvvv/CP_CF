#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int solveTab(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= 6; ++j) {
            if(i-j>=0)
                dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    return dp[n];
}
// int solveMem(int n) {
//     if (n == 0) return 1; 

//     if (dp[n] != -1) return dp[n];

//     int ways = 0;
//     for (int i = 1; i <= 6; ++i) {
//         if(n-i>=0)
//             ways = (ways + solveMem(n - i)) % MOD;
//     }

//     return dp[n] = ways;
// }

void solve() {
    int n;
    cin >> n;
    cout << solveTab(n) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
