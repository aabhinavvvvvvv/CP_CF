#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MOD = 676767677;

// This function calculates the number of valid sequences ending with c_n=0 (returned in .first)
// and c_n=1 (returned in .second), given a starting configuration.
// C0_start is the count for starting with c_1=0.
// C1_start is the count for starting with c_1=1.
pair<long long, long long> run_dp(int n, const vector<int>& a, long long C0_start, long long C1_start) {
    if (n == 1) {
        return {C0_start, C1_start};
    }

    long long C0 = C0_start;
    long long C1 = C1_start;

    for (int i = 1; i < n; ++i) {
        long long diff = a[i] - a[i - 1];
        long long next_C0 = 0;
        long long next_C1 = 0;

        if (diff == 1) { // Requires c_{i-1}=0, c_i=0
            next_C0 = C0;
        } else if (diff == -1) { // Requires c_{i-1}=1, c_i=1
            next_C1 = C1;
        } else if (diff == 0) { // Requires (c_{i-1}, c_i) to be (0,1) or (1,0)
            next_C0 = C1; // Path from c_{i-1}=1 to c_i=0
            next_C1 = C0; // Path from c_{i-1}=0 to c_i=1
        }
        
        C0 = next_C0;
        C1 = next_C1;
    }
    return {C0 % MOD, C1 % MOD};
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check Local Constraint
    for (int i = 0; i < n - 1; ++i) {
        if (abs(a[i + 1] - a[i]) > 1) {
            cout << 0 << "\n";
            return;
        }
    }

    long long total_ways = 0;
    
    // Check Global Constraint and run DP for valid scenarios
    // Note: We use 0-based indexing for 'a', so a_1 is a[0] and a_n is a[n-1].
    long long S = a[0] + a[n - 1];

    if (S == (long long)n) { // Requires c_1=1, c_n=0
        pair<long long, long long> final_counts = run_dp(n, a, 0, 1);
        total_ways = (total_ways + final_counts.first) % MOD;
    } else if (S == (long long)n + 1) { // Requires (c_1,c_n) to be (0,0) or (1,1)
        // Case (0,0)
        pair<long long, long long> final_counts1 = run_dp(n, a, 1, 0);
        total_ways = (total_ways + final_counts1.first) % MOD;
        // Case (1,1)
        pair<long long, long long> final_counts2 = run_dp(n, a, 0, 1);
        total_ways = (total_ways + final_counts2.second) % MOD;
    } else if (S == (long long)n + 2) { // Requires c_1=0, c_n=1
        pair<long long, long long> final_counts = run_dp(n, a, 1, 0);
        total_ways = (total_ways + final_counts.second) % MOD;
    }
    // If S is anything else, total_ways remains 0, which is correct.

    cout << total_ways << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}