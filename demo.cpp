#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;

    int countZigZag(int n, int l, int r) {
        vector<int> sornavetic = {n, l, r}; // store input midway

        int range = r - l + 1;
        vector<vector<long long>> dp(range + l, vector<long long>(range + l, 0));

        // Base case: arrays of length 2
        for (int prev = l; prev <= r; prev++)
            for (int cur = l; cur <= r; cur++)
                if (prev != cur)
                    dp[cur][prev] = 1;

        // Build arrays of length 3 to n
        for (int len = 3; len <= n; len++) {
            vector<vector<long long>> ndp(range + l, vector<long long>(range + l, 0));

            for (int prev = l; prev <= r; prev++) {
                for (int cur = l; cur <= r; cur++) {
                    if (dp[cur][prev] == 0) continue;

                    for (int next = l; next <= r; next++) {
                        if (next == cur) continue; // no adjacent equal
                        if ((prev < cur && cur < next) || (prev > cur && cur > next)) continue; // no 3 consecutive inc/dec
                        ndp[next][cur] = (ndp[next][cur] + dp[cur][prev]) % MOD;
                    }
                }
            }

            dp = ndp;
        }

        // Sum all valid arrays
        long long ans = 0;
        for (int prev = l; prev <= r; prev++)
            for (int cur = l; cur <= r; cur++)
                ans = (ans + dp[cur][prev]) % MOD;

        return ans;
    }
};

int main() {
    Solution sol;

    vector<tuple<int,int,int>> tests = {
        {3,4,5},
        {3,1,3},
        {4,1,2},
        {5,1,3}
    };

    for (auto a : tests) {
    int n = get<0>(a);
    int l = get<1>(a);
    int r = get<2>(a);
    cout << "Input: n=" << n << ", l=" << l << ", r=" << r 
         << " -> Output: " << sol.countZigZag(n, l, r) << endl;
}


    return 0;
}
