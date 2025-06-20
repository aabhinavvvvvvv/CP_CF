#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
int n, m;

int dp[11][1001][1001];

int countPairs(int i, int lastA, int lastB) {
    if(i==m) return 1;
    if(lastA>n || lastB<0 || lastA>lastB) return 0;
    if(dp[i][lastA][lastB]!=-1) return dp[i][lastA][lastB];
    return dp[i][lastA][lastB] = (countPairs(i+1,lastA,lastB)+countPairs(i+1,lastA+1,lastB)+countPairs(i+1,lastA,lastB-1)-countPairs(i+1,lastA+1,lastB+1))%MOD;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    cout << countPairs(0, 1, n) << '\n';
    return 0;
}
