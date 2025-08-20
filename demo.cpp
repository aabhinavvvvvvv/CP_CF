#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxTasks(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        int maxNeed = 0;
        for (int i = 0; i < n; i++) {
            maxNeed = max({maxNeed, A[i], B[i]});
        }
        int maxPoints = accumulate(C.begin(), C.end(), 0);
        int LIM = maxNeed + maxPoints + 2;

        // dp[p][s] = maximum tasks completed with (p,s)
        vector<vector<int>> dp(LIM+1, vector<int>(LIM+1, -1));
        dp[1][1] = 0;

        for (int idx = 0; idx < n; idx++) {
            // We process each task once → like 0/1 knapsack
            vector<vector<int>> newdp = dp;

            for (int p = 1; p <= LIM; p++) {
                for (int s = 1; s <= LIM; s++) {
                    if (dp[p][s] == -1) continue;

                    if (p >= A[idx] || s >= B[idx]) {
                        int reward = C[idx];
                        // distribute reward
                        for (int addP = 0; addP <= reward; addP++) {
                            int newP = min(LIM, p + addP);
                            int newS = min(LIM, s + (reward - addP));
                            newdp[newP][newS] = max(newdp[newP][newS], dp[p][s] + 1);
                        }
                    }
                }
            }
            dp.swap(newdp);
        }

        int ans = 0;
        for (int p = 1; p <= LIM; p++) {
            for (int s = 1; s <= LIM; s++) {
                ans = max(ans, dp[p][s]);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> A1 = {1, 1, 2, 7};
    vector<int> B1 = {1, 3, 4, 4};
    vector<int> C1 = {2, 3, 1, 1};
    cout << sol.maxTasks(A1, B1, C1) << endl; // Expected: 4

    vector<int> A2 = {1, 2, 4, 9};
    vector<int> B2 = {1, 2, 4, 9};
    vector<int> C2 = {2, 1, 2, 3};
    cout << sol.maxTasks(A2, B2, C2) << endl; // Expected: 3

    return 0;
}
